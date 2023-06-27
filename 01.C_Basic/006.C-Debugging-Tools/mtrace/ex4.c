#include <stdlib.h>
#include <mcheck.h>

int main() 
{
    mtrace();
    char a = 5;
    char* ptr = (char*)malloc(10 * sizeof(char));  // cấp phát 10 byte
    ptr = &a;
    free(ptr);  // giải phóng bộ nhớ
    muntrace();
    return 0;
}