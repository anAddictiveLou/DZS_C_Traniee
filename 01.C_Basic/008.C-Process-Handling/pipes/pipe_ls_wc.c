#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define handle_error(msg) \
    do { fprintf(stderr, "Error: %s\n", msg);  \
    exit(EXIT_FAILURE); } while (0)
#define RD 0
#define WR 1

int main(int argc, char *argv[])
{
    int pfd[2];
    pipe(pfd);
    switch (fork())
    {
    case -1:
        handle_error("fork() failed!");
    case 0:                      
        close(pfd[RD]);
        if (pfd[WR] != STDOUT_FILENO)
        {
            dup2(pfd[WR], STDOUT_FILENO);
            close(pfd[WR]);
        }
        execlp("ls", "ls", (char *)NULL); 
        handle_error("ls failed!");
    default: 
        break;
    }
    switch (fork())
    {
    case -1:
        handle_error("fork() failed!");
    case 0:                     
        close(pfd[WR]);
        if (pfd[RD] != STDIN_FILENO)
        { 
            dup2(pfd[RD], STDIN_FILENO);
            close(pfd[RD]);
        }
        execlp("wc", "wc", "-l", (char *)NULL);
        handle_error("wc -l failed!");
    default:
        break;
    }
    close(pfd[RD]);
    close(pfd[WR]);
    wait(NULL);
    wait(NULL);
    exit(EXIT_SUCCESS);
}
