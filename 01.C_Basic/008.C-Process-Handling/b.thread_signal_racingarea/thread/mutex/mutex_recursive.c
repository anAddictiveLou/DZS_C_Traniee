#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t recursive_mutex;
int shared_variable = 0;

void recursive_function(int recursion_depth) {
    // Base case: return if recursion depth reaches 0
    if (recursion_depth == 0) {
        return;
    }

    // Acquire the recursive mutex
    pthread_mutex_lock(&recursive_mutex);

    // Increment the shared variable
    shared_variable++;

    // Print the current thread and shared variable value
    printf("Thread %ld: Shared variable = %d\n", pthread_self(), shared_variable);

    // Recursive call with reduced recursion depth
    recursive_function(recursion_depth - 1);

    // Release the recursive mutex
    pthread_mutex_unlock(&recursive_mutex);
}

void* thread_function(void* arg) {
    int recursion_depth = *((int*)arg);
    recursive_function(recursion_depth);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int recursion_depths[NUM_THREADS] = {3, 2, 4}; // Define different recursion depths for threads

    // Initialize the recursive mutex
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&recursive_mutex, &mutex_attr);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)&recursion_depths[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the recursive mutex
    pthread_mutex_destroy(&recursive_mutex);

    return 0;
}
