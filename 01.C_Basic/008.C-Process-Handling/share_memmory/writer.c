#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char** argv)
{
    const int SIZE = 4096;
    const char* name = "share mem";
    const char* msg1 = "Hello World\n";
    void* ptr = NULL;
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    strcpy(ptr, msg1);
    exit(EXIT_SUCCESS);
}