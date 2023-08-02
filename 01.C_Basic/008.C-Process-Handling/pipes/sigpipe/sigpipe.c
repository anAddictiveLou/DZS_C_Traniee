#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#define BUF_SIZE 100
#define RD 0
#define WR 1

int main(int argc, char** argv)
{
    int filedes[2];
    char fd_arg[BUF_SIZE] = {0};
    pipe(filedes);
    printf("%dfcntl(filedes[RD], 1032);
    char* msg = "Hello World\n";
    switch (fork())
    {
    case -1:
        puts("fork() failed!");
        exit(EXIT_FAILURE);
    case 0:
        /* Child process */
        close(filedes[WR]);
        close(filedes[RD]);

        break;
    default:
        /* Parent process */
        sleep(1);
        close(filedes[RD]);
        signal(SIGPIPE, SIG_IGN);
        if (write(filedes[WR], msg, strlen(msg)) < 0) ;
            perror("write");
        wait(NULL);
        break;
    }
    exit(EXIT_SUCCESS);
}
