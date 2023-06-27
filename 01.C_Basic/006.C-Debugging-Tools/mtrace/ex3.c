#include <stdlib.h>
#include <mcheck.h>

int main() {
    mtrace();
    char* ptr = (char*)malloc(10 * sizeof(char));  // cấp phát 10 byte
    free(ptr);  // giải phóng bộ nhớ
    free(ptr);  // cố gắng giải phóng bộ nhớ đã được giải phóng -> double free
    muntrace();
    return 0;

}