#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 100
#define RD 0
#define WR 1

int main(int argc, char** argv)
{
    int filedes[2];
    char fd_arg[BUF_SIZE] = {0};
    pipe(filedes);
    char msg[BUF_SIZE] = {0};
    switch (fork())
    {
    case -1:
        puts("fork() failed!");
        exit(EXIT_FAILURE);
    case 0:
        /* Child process */
        close(filedes[WR]);
        sprintf(fd_arg, "%d", filedes[RD]);
        execlp(argv[1], argv[1], fd_arg, (char*) NULL);
        break;
    default:
        /* Parent process */
        close(filedes[RD]);
        for (;;)
        {
            printf("msg to child process: ");
            fgets(msg, BUF_SIZE, stdin);
            write(filedes[WR], msg, strlen(msg));
            sleep(1);
        }
        wait(NULL);
        break;
    }
    exit(EXIT_SUCCESS);
}
