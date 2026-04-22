#include "circular_queue.h"

#include <stdio.h>

CircularQueue* CreateCircularQueue()
{
    CircularQueue* res = (CircularQueue*)malloc(sizeof(CircularQueue));

    res->front = 0;
    res->rear = 0;

    return res;
}

int isCircularQueueEmpty(CircularQueue* val)
{
    if (val->front == val->rear) return true;
    else return false;
}

int isCircularQueueFull(CircularQueue* val)
{
    if ((val->rear + 1) % SIZE_MAX == val->front) return true;
    else return false;
}

char enCircularQueue(CircularQueue* val, char data)
{
    if (isCircularQueueFull(val))
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

char deCircularQueue(CircularQueue* val)
{
    if (isCircularQueueEmpty(val))
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

char peekCircularQueue(CircularQueue* val)
{
    if (isCircularQueueEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        // front의 다음 칸이 실제 첫 번째 데이터
        return val->data[(val->front + 1) % SIZE_MAX];
    }
}

void printCircularQueue(CircularQueue* val)
{
    printf("CircularQueue [");

    int i = (val->front + 1) % SIZE_MAX;
    while (i != (val->rear + 1) % SIZE_MAX)
    {
        printf("%c", val->data[i]);

        if (i != val->rear) printf(", ");
        i = (i + 1) % SIZE_MAX;
    }

    printf("]\n");
}
