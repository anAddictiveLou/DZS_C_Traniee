#include <stdio.h>

typedef int (*fptr) (int, int);

int func1(int a, int b, fptr fp1)
{
    printf("Call func2 by callback: %d\n", fp1(a, b));
    return a + b;
}

int func2(int a, int b)
{
    return a - b;
}

int main()
{
    fptr fp1 = func2;
    int a = 10, b = 20;
    printf("func1 return: %d\n", func1(a, b, fp1));
    return 0;
}