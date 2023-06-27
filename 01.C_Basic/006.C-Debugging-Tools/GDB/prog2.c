#include <stdio.h>
#include <string.h>
#define SIZE_INPUT 20
#define SIZE_BUFFER (SIZE_INPUT / 2)

void vulnerableFunction(char *input) 
{
    char buffer[SIZE_BUFFER];
    strcpy(buffer, input);
}

int main() 
{
    char input[SIZE_INPUT];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    vulnerableFunction(input);

    printf("Execution continues...\n");

    return 0;
}
