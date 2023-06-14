#include <stdio.h>
int sumOfArr(int const * const arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d\n", sumOfArr(arr, sizeof(arr)/ sizeof(int)));


    int* ptr = NULL;

    /* Check pointer does not pointer to particular memory */
    if (ptr == NULL) {
        ptr = (int*)calloc(10, sizeof(int));    // Dynamic memory allocation
    }

    /* Use ptr for handle block of allocated memory*/

    /* Release block of memory for program */
    free(ptr);
    ptr = NULL; // Avoid dagling pointer

}




