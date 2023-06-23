#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[8];
    strcpy(buffer, input);
}

int main() {
    char input[16];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    vulnerableFunction(input);

    printf("Execution continues...\n");

    return 0;
}
