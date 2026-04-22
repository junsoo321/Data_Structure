#pragma once

#include <stdlib.h>

#define SIZE_MAX 100

#define true 1
#define false 0

typedef struct Queue {
    int front;
    int rear;

    char data[100];
} Queue;

Queue* CreateQueue();
int isQueueEmpty(Queue* val);
int isQueueFull(Queue* val);

char enQueue(Queue* val, char data);
char deQueue(Queue* val);

char peek(Queue* val);

void printQueue(Queue* val);