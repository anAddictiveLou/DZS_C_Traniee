#include <stdio.h>

int main(int argc, char* argv[])
{ 
    FILE* fp = fopen(argv[1], "r"); 
    char word[100] = {0}; 
    while (fscanf(fp , "%s" , word )> 0) 
    {
        printf("%s", word);
    } 
    return 0; 
}