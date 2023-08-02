#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    void** data;
    int front;
    int rear;
} CircularQueue;

void initializeQueue(CircularQueue* queue);
bool isFull(CircularQueue* queue);
bool isEmpty(CircularQueue* queue);
void enqueue(CircularQueue* queue, void* item);
void* dequeue(CircularQueue* queue);
void* front(CircularQueue* queue);
void* rear(CircularQueue* queue);

#endif /* CIRCULAR_QUEUE_H */
