#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

void initializeQueue(CircularQueue* queue) 
{
    queue->data = (void**)calloc(MAX_SIZE, sizeof(void*));
    queue->front = -1;
    queue->rear = -1;
}


bool isFull(CircularQueue* queue) 
{
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
           (queue->front == queue->rear + 1);
}

bool isEmpty(CircularQueue* queue) 
{
    return queue->front == -1;
}

void enqueue(CircularQueue* queue, void* item) {
    if (isFull(queue)) {
        printf("Error: Queue is full.\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
}

void* dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    void* item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return item;
}

void* front(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    return queue->data[queue->front];
}

void* rear(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    return queue->data[queue->rear];
}
