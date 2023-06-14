#include <stdio.h>
#include <stdlib.h>
#include "./inc/lib.h"

static int sA = 10;

static int eventHandler(int* a, int b)
{
    return *a + b;
}

void testStatic1()
{
    static int sA1;
    printf("%d ", sA1++);
}

void testStatic2()
{
    static int sA1 = 10;
    printf("%d ", sA1++);
}

int main(){
    setcb(eventHandler);
    //printf("\n%d\n", b);
    //printf("\nAdrress of c var in main.c: %p\n", &c);
    int a = callcb(&sA, 6);
    printf("%d \n", a);
    for (int i = 0; i < 10; i++)
        testStatic1();
    for (int i = 0; i < 10; i++)
        testStatic1();
}