#pragma once

#include <stdlib.h>

#define true 1
#define false 0

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LinkedQueue {
    Node* front;
    Node* rear;
    int size;
} LinkedQueue;

LinkedQueue* CreateLinkedQueue();
int isLinkedQueueEmpty(LinkedQueue* val);

char enLinkedQueue(LinkedQueue* val, char data);
char deLinkedQueue(LinkedQueue* val);

char peekLinkedQueue(LinkedQueue* val);

void printLinkedQueue(LinkedQueue* val);
void destroyLinkedQueue(LinkedQueue* val);
