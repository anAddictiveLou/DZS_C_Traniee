#include <stdio.h>

int foo(int a, int b)
{
    int lvar1 = 0xa;
    int lval2 = 0x14;
    return a + b + lvar1 + lval2;
}

void swap(int* a, int* b)
{
    int t1 = *a;
    int t2 = *b;
    *a = t2;
    *b = t1;
}

int funcWithManyParas(int a, int b, int c, int d, int e, int f, int g, int h, int j)
{
    long int lvar1 = 0xa;
    long int lvar2 = 0xb;
    return a + b + c + d + e + f + g + h + j; 
}

int main(int argc, char *argv[])
{
    int a = 0x1, b = 0x2;
    funcWithManyParas(0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9);
    return 1;
}