#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int* fd;
    int count = 0;
    for (;;)
    {
        fd = (int*) malloc(2 * sizeof(int));
        if (pipe(fd) == -1)
            break;
        count++;   
    }
    printf("Max pipes created: %d\n", count);
}