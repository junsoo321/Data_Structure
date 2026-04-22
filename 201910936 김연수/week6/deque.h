#pragma once

#include <stdlib.h>

#define SIZE_MAX 100

#define true 1
#define false 0

typedef struct Deque {
    int front;
    int rear;

    char data[SIZE_MAX];
} Deque;

Deque* CreateDeque();
int isDequeEmpty(Deque* val);
int isDequeFull(Deque* val);

char enqueueFront(Deque* val, char data);
char dequeueFront(Deque* val);

char enqueueRear(Deque* val, char data);
char dequeueRear(Deque* val);

char peekFront(Deque* val);
char peekRear(Deque* val);

void printDeque(Deque* val);
