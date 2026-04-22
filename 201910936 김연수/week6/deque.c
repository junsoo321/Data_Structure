#include "deque.h"

#include <stdio.h>

Deque* CreateDeque()
{
    Deque* res = (Deque*)malloc(sizeof(Deque));

    res->front = 0;
    res->rear = 0;

    return res;
}

int isDequeEmpty(Deque* val)
{
    if (val->front == val->rear) return true;
    else return false;
}

int isDequeFull(Deque* val)
{
    if ((val->rear + 1) % SIZE_MAX == val->front) return true;
    else return false;
}

char enqueueFront(Deque* val, char data)
{
    if (isDequeFull(val))
    {
        printf("Full Queue !");
        return false;
    }
    else
    {
        val->data[val->front] = data;
        val->front = (val->front - 1 + SIZE_MAX) % SIZE_MAX;
        return data;
    }
}

char dequeueFront(Deque* val)
{
    if (isDequeEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        val->front = (val->front + 1) % SIZE_MAX;
        return val->data[val->front];
    }
}

char enqueueRear(Deque* val, char data)
{
    if (isDequeFull(val))
    {
        printf("Full Queue !");
        return false;
    }
    else
    {
        val->rear = (val->rear + 1) % SIZE_MAX;
        val->data[val->rear] = data;
        return data;
    }
}

char dequeueRear(Deque* val)
{
    if (isDequeEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        char res = val->data[val->rear];
        val->rear = (val->rear - 1 + SIZE_MAX) % SIZE_MAX;
        return res;
    }
}

char peekFront(Deque* val)
{
    if (isDequeEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        return val->data[(val->front + 1) % SIZE_MAX];
    }
}

char peekRear(Deque* val)
{
    if (isDequeEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        return val->data[val->rear];
    }
}

void printDeque(Deque* val)
{
    printf("Deque [");

    int total = (val->rear - val->front + SIZE_MAX) % SIZE_MAX;
    int i = (val->front + 1) % SIZE_MAX;

    for (int count = 0; count < total; count++)
    {
        printf("%c", val->data[i]);

        if (count < total - 1) printf(", ");
        i = (i + 1) % SIZE_MAX;
    }

    printf("]\n");
}
