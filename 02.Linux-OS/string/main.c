#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE] = "Helloworld";
char pwd[BUFFER_SIZE] = "password";

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        exit(1);
    }
    
    strcpy(buffer, argv[2]);
    if (strcmp(argv[1], pwd) == 0)
    {
        printf("right password\n");   
        printf("MSG: %s\n", buffer);     
    }
    else
    {
        printf("wrong password\n");
    }
    

    return 0;
}