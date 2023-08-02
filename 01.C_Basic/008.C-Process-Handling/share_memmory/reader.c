#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#define BUFF_SIZE 4096

int main(int argc, char** argv)
{
    const int SIZE = 4096;
    const char* name = "share mem";
    char buff[BUFF_SIZE] = {0};
    void* ptr = NULL;
    int shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    strcpy(buff, ptr);
    printf("%s", buff);
    shm_unlink(name);
    exit(EXIT_SUCCESS);
}