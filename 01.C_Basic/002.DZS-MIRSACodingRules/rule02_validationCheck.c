#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int valCheckUsingIfElse(void)
{
    int age;
    printf("valCheckUsingIfElse\n");
    do {
        printf("Enter your age is an integer\n");
        scanf("%d", &age);
        if (age < 0) {
            printf("Invalid age\n");
            exit(1);
        } 
    } while (age < 0);
    return age;
}
int valCheckUsingAssert(void)
{
    int age;
    printf("valCheckUsingAssert\n");
    printf("Enter your age is an integer\n");
    scanf("%d", &age);
    assert(age > 0);
    return age;
}

int age;

int main(int argc, char* argv[])
{
    /* Declaration*/
    int age = 0;
    assert(argc == 2); 
    
    /* Validation check should be placed between Declaration and Coding of function*/
    int opt = atoi(argv[1]);
    if (opt == 1) {
        age = valCheckUsingIfElse();
    } else if (opt == 2) {
        age = valCheckUsingAssert();
    } else {
        printf("Invalid opt\n");
        exit(1);
    }
    
    /* Coding of function*/
   printf("Your age is: %d\n",age);
    
    return 0;
}