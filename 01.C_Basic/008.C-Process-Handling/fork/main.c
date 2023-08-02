#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);
    printf("pipe capacity = %d\n", fcntl(fd[0], F_GETPIPE_SZ));
    exit(EXIT_SUCCESS);
}