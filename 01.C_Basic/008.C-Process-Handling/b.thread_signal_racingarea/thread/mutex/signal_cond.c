#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS_TO_PRODUCE 20

int buffer[BUFFER_SIZE];
int in = 0;  // Index for the producer
int out = 0; // Index for the consumer
int count = 0; // Number of items in the buffer`

pthread_mutex_t mutex;
pthread_cond_t cond_empty, cond_full;

void* producer(void* arg) {
    for (int i = 1; i <= NUM_ITEMS_TO_PRODUCE; i++) {
        pthread_mutex_lock(&mutex);
        
        // Wait if the buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&cond_empty, &mutex);
        }
        
        // Produce an item and add it to the buffer

            buffer[in] = i;
            in = (in + 1) % BUFFER_SIZE;
            count++;
            printf("Produced: %d\n", i);


        // Signal that the buffer is not empty anymore
        pthread_cond_signal(&cond_full);
        
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void* consumer(void* arg) {
    int consumed_items = 0;
    while (consumed_items < NUM_ITEMS_TO_PRODUCE) {
        pthread_mutex_lock(&mutex);
        
        // Wait if the buffer is empty
        while (count == 0) {
            pthread_cond_wait(&cond_full, &mutex);
        }
        
        // Consume an item from the buffer
   int item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            count--;
            printf("Consumed: %d\n", item);
            consumed_items++;


        // Signal that the buffer is not full anymore
        pthread_cond_signal(&cond_empty);
        
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_empty, NULL);
    pthread_cond_init(&cond_full, NULL);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_empty);
    pthread_cond_destroy(&cond_full);

    return 0;
}
