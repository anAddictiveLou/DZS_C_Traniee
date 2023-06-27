#include <stdlib.h>
#include <stdio.h>
#include <mcheck.h>

int main() {
    mtrace();
    char* ptr = (char*)malloc(10 * sizeof(char));  // cấp phát 10 byte
    ptr[10] = 'a';  // truy cập sau cùng - ghi vào byte thứ 11
    free(ptr);
    printf("\n%d\n", ptr[10]);
    muntrace();
    return 0;
}