#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1000
#define RD 0
#define WR 1

int main(int argc, char** argv)
{
    char buf[BUF_SIZE] = {0};
    int num_bytes = 0;
    for (;;)
    {
        if (0 != (num_bytes = read(atoi(argv[1]), buf, BUF_SIZE)))
        {
            printf("msg from parent process: %s", buf);
            memset(buf, 0, BUF_SIZE);
        }
    }
    exit(EXIT_SUCCESS);
}
