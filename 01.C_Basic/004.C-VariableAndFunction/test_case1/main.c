#include <stdio.h>

extern int x;
int sum(int, int, int);

int main()
{
    printf("Hello World!%d\n", sum(4, 6, 8));
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}