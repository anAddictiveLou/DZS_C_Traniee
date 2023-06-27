#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int* ptr = (int*) malloc(SIZE * sizeof(int));
    for (int i = 0; i <= SIZE; i++)
        ptr[i] = i;
    free(ptr);
    return 0;
}