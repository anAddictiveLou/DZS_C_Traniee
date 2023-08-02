#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 100

int main(char argc, char** argv)
{
    int fdw, fdr;
    char* str = "Hello World ver3\n";
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    fdw = open("text.txt", O_WRONLY | O_APPEND);
    write(fdw, str, strlen(str));
    fdr = open("text.txt", O_RDONLY);
    read(fdr, buf, BUF_SIZE);
    printf("%s", buf);
    close(fdr);
    close(fdw);
    exit(EXIT_SUCCESS);
}