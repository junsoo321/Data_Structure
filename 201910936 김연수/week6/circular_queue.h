#pragma once

#include <stdlib.h>

#define SIZE_MAX 100

#define true 1
#define false 0

typedef struct CircularQueue {
    int front;
    int rear;

    char data[SIZE_MAX];
} CircularQueue;

CircularQueue* CreateCircularQueue();
int isCircularQueueEmpty(CircularQueue* val);
int isCircularQueueFull(CircularQueue* val);

char enCircularQueue(CircularQueue* val, char data);
char deCircularQueue(CircularQueue* val);

char peekCircularQueue(CircularQueue* val);

void printCircularQueue(CircularQueue* val);
