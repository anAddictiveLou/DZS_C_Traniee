#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 3

pthread_mutex_t mutex;
int shared_variable = 0;

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    struct timespec timeout;

    // Set the timeout for the thread (in this example, 2 seconds)
    clock_gettime(CLOCK_REALTIME, &timeout);
    timeout.tv_sec += 5;
    printf("Thread %d is trying to acquire the mutex...\n", thread_id);

    // Try to acquire the mutex with a timed wait
    if (pthread_mutex_timedlock(&mutex, &timeout) == 0) {
        printf("Thread %d acquired the mutex!\n", thread_id);

        // Increment the shared variable while holding the mutex
        shared_variable++;

        // Simulate some work by sleeping for a short period
         sleep(1);

        // Release the mutex
        pthread_mutex_unlock(&mutex);

        printf("Thread %d released the mutex.\n", thread_id);
    } else {
        printf("Thread %d couldn't acquire the mutex within the timeout.\n", thread_id);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    printf("Final value of the shared variable: %d\n", shared_variable);

    return 0;
}
