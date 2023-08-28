#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "sh.h"

char* symbols = "<>|&";
char buffer[BUF_SIZE];

void parse_exec(char* buffer, struct exec* ret)
{
    char* args[ARGS];
    char* save_ptr = NULL;
    char* token = strtok_r(buffer, " ", &save_ptr); 
    args[0] = calloc(BUF_SIZE, sizeof(char));
    snprintf(args[0], BUF_SIZE, "/usr/bin/%s", token);
    ret->name = args[0];
    for (int i = 1; ; i++)
    {
        args[i] = strtok_r(NULL, " ", &save_ptr); 
        if (NULL == args[i])
            break;
    }
    ret->args = args;
}

void parse_redir(char* buffer, struct redir* ret)
{
    char* save_ptr = NULL;
    char* token = strtok_r(buffer, "<>", &save_ptr);
    parse_exec(token, &ret->prog);
    ret->file_name = strtok_r(NULL, " ", &save_ptr);
}

void parse_pipe(char* buffer, struct pipe* ret)
{
    char* save_ptr = NULL;
    char* token = strtok_r(buffer, "|", &save_ptr);
    parse_exec(token, &ret->prog[0]);
    parse_exec(save_ptr, &ret->prog[1]);
}

struct cmd* parse_cmd(char* buffer)
{
    if (NULL == buffer)
        return NULL;
    char* pos = NULL;
    struct cmd* ret = (struct cmd*) calloc(1, sizeof(struct cmd));
    if(NULL == (pos = strpbrk(buffer, symbols)))
    {
        ret->type = EXEC;
        parse_exec(buffer, &ret->run.handle_exec);
    }
    else
    {
        switch (*pos)
        {
        case '>':
            ret->type = REDIR;
            ret->run.handle_redir.redir_type = OUTPUT;
            parse_redir(buffer, &ret->run.handle_redir);
            break;

        case '<':
            ret->type = REDIR;
            ret->run.handle_redir.redir_type = INPUT;
            parse_redir(buffer, &ret->run.handle_redir);
            break;

        case '|':
            ret->type = PIPE;
            parse_pipe(buffer, &ret->run.handle_pipe);
            break;

        case '&':
            ret->type = BACK;
            buffer[strlen(buffer) - 1] = '\0';
            parse_exec(buffer, &ret->run.handle_back.prog);
        default:
            break;
        }
        
    }
    return ret;
}

void handle_cmd_exec(struct exec command)
{
    execv(command.name, command.args);
    printf("%s does not found\n", command.name);
}

void handle_cmd_back(struct back command)
{
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    handle_cmd_exec(command.prog);
}

void handle_cmd_redir(struct redir command)
{
    switch (command.redir_type)
    {
    case INPUT:
        if (fork() == 0)
        {
            close(STDIN_FILENO);
            open(command.file_name, O_RDONLY);
            handle_cmd_exec(command.prog);
        }
        break;
    
    case OUTPUT:
        if (fork() == 0)
        {
            close(STDOUT_FILENO);
            open(command.file_name, O_CREAT | O_WRONLY);
            handle_cmd_exec(command.prog);
        }
        break;   
    }
}

void handle_cmd_pipe(struct pipe command)
{
    int fd[2] = {0};
    pipe(fd);

    if (fork() == 0)
    {
        close(fd[RD]);
        if (fd[WR] != STDOUT_FILENO)
        {
            dup2(fd[WR], STDOUT_FILENO);
            close(fd[WR]); 
        }
        handle_cmd_exec(command.prog[0]);
    } 
    if (fork() == 0)
    {
        close(fd[WR]);
        if (fd[RD] != STDIN_FILENO)
        {
            dup2(fd[RD], STDIN_FILENO);
            close(fd[RD]);
        }
        handle_cmd_exec(command.prog[1]);
    }

    close(fd[RD]);
    close(fd[WR]);
    wait(NULL);
    wait(NULL);
}

void handle_cmd(struct cmd* command)
{
    if (NULL == command)
        return;
    if (fork() == 0)
    {
        /* child process */
        switch (command->type)
        {
        case EXEC:
            handle_cmd_exec(command->run.handle_exec);
            break;
        case REDIR:
            handle_cmd_redir(command->run.handle_redir);
            break;
        case PIPE:
            handle_cmd_pipe(command->run.handle_pipe);
            break;
        case BACK:
            handle_cmd_back(command->run.handle_back);
            break;
        default:
            break;
        }    
    }
    else
    {
        /* parent process */
        if (BACK != command->type)
        {
            wait(NULL);
        }
        memset(buffer, 0, BUF_SIZE);
    }
}

int main(int argc, char** argv)
{   

    int fd = 0;
    while ((fd = open("/dev/console", O_RDWR)) <= 2)
    if (fd > 2)
        close(fd);
    
    while (1)
    {
        printf("$ ");   
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (buffer[0] == 'c' && buffer[1] == 'd' && buffer[2] == ' ')
        {
            chdir(buffer+3);
        }
        else
        {
            handle_cmd(parse_cmd(buffer));
        }
    }
    exit(EXIT_SUCCESS);
}