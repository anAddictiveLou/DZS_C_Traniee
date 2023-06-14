#include <stdio.h>

void a(int i)
{
    if (i > 0) {
        a(--i);
    } else {
        printf("i has reached to zero\n ");
    }
}

int main() {
    a(1);
}