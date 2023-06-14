#include <stdio.h>
#include <stdlib.h>
#include "./inc/lib.h"

typedef int (*cb) (int*, int); 
static cb gCallBack;
static int c = 100;

void setcb(cb userFunc)
{
    gCallBack = userFunc;
}

int callcb(int* a, int b)
{
    printf("In callback function\n");
    printf("Address of c var in lib.c: %p", &c);
    *a = 20;
    return gCallBack(a, b);
}

