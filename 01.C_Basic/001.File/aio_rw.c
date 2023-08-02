#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 100

int main(char argc, char** argv)
{
    int fdw;
    char* str = "Hello World ver3\n";
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    exit(EXIT_SUCCESS);
}