#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>

void child_process(int pipe_fd, int num_blocks, int block_size) {
    char* data_block = (char*) malloc(block_size);
    memset(data_block, 'x', block_size);

    for (int i = 0; i < num_blocks; i++) {
        write(pipe_fd, data_block, block_size);
    }

    free(data_block);
    close(pipe_fd);
}

void parent_process(int pipe_fd, int num_blocks, int block_size) {
    struct timeval start_time, end_time;
    int total_bytes = 0;

    gettimeofday(&start_time, NULL);

    char* data = (char*) malloc(block_size);
    while (read(pipe_fd, data, block_size) > 0) {
        total_bytes += block_size;
    }

    gettimeofday(&end_time, NULL);

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    double bandwidth = total_bytes / elapsed_time;

    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Bandwidth: %.2f bytes/second\n", bandwidth);

    free(data);
    close(pipe_fd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num_blocks> <block_size>\n", argv[0]);
        return 1;
    }

    int num_blocks = atoi(argv[1]);
    int block_size = atoi(argv[2]);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        close(pipe_fd[0]); // Close the read end of the pipe in the child process
        child_process(pipe_fd[1], num_blocks, block_size);
    } else {
        close(pipe_fd[1]); // Close the write end of the pipe in the parent process
        parent_process(pipe_fd[0], num_blocks, block_size);
        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
