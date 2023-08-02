#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

#define BUF_SIZE 1000

int main(int argc, char** argv)
{
    char buf[BUF_SIZE] = {0};
    fgets(buf, BUF_SIZE, stdin);
    fclose(stdin);
    fputs(buf, stdout);
    fclose(stdout);
    exit(EXIT_SUCCESS);
}