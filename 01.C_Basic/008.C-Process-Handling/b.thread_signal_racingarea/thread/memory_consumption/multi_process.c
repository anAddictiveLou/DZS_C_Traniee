#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

void perform_memory_intensive_task() {
    int *array = NULL;
    const int num_elements = 10000000; // Allocate around 40 MB of memory

    array = (int*)malloc(sizeof(int) * num_elements);
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Access the allocated memory to prevent it from being optimized away
    for (int i = 0; i < num_elements; ++i) {
        array[i] = i;
    }

    free(array);
}

int main() {
    // Record resource usage before starting the task
    struct rusage start_usage;
    getrusage(RUSAGE_SELF | RUSAGE_CHILDREN, &start_usage);

    // Simulate a multi-process task
    for (int i = 0; i < 3; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Child %d executing memory-intensive task...\n", getpid());
            perform_memory_intensive_task();
            printf("Child %d finished.\n", getpid());
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for all child processes to complete
    int status;
    pid_t pid;
    while ((pid = wait(&status)) != -1) {
        printf("Child %d exited with status %d\n", pid, status);
    }

    // Record resource usage after the task is complete
    struct rusage end_usage;
    getrusage(RUSAGE_SELF | RUSAGE_CHILDREN, &end_usage);
    long memory_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;

    printf("\nTotal memory usage: %ld KB\n", memory_usage);

    return 0;
}
