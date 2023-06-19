#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (long long a, long long b)
{
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp; 
}

void alloc(int *ptr, size_t size)
{
    *(int**)ptr = (int*)malloc(size * sizeof(int));
    int* ptrB = *(int**)ptr;
    for (int i = 0, a = 10; i < 10; i++)
    {
        *ptrB++ = a++;
    }
}

int sumArr(int const* const arr, size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum+=arr[i];        
    return sum;
}

int main()
{       
    int a = 10, b = 100;
    swap((long long)&a, (long long)&b); 
    int* ptr = NULL;
    alloc((int*)&ptr, 10);
    printf("Verify swap func  : %d %d\n", a, b);
    printf("Verify alloc func : ");
    int *root = ptr;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *ptr++);
    }
    int *ptr2 = (int*) calloc(10, sizeof(int) * 10);
    printf("\nSum of arr        : %d\n", sumArr(root, 10));
}
