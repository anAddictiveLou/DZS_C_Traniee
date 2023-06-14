#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

typedef int (*cb) (int*, int); 


void setcb(cb);
int callcb(int* , int);

#endif