#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = NULL;
    p = (int*) calloc(10, sizeof(int));
    *p = 10;

    // p = (int*) realloc(NULL, 0);
    // if (p == NULL) {
    //     printf("p = NULL\n");
    // } else {
    //     printf("Undefined behavior\n");
    //     printf("%d\n", *p);
    // }

    free(p);
    free(p);

    return 0;
}