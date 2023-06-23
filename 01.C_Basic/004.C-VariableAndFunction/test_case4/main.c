#include <stdio.h>
int a = 10;
extern int a = 4;
int main()
{
    printf("sum() return: %d\n", a);
    return 0;
}