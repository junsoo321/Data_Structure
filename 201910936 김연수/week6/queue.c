#include "queue.h"

#include <stdio.h>

Queue* CreateQueue()
{
    Queue* res = (Queue*)malloc(sizeof(Queue));

    res->front = -1;
    res->rear = -1;

    return res;
}

int isQueueEmpty(Queue* val)
{
    if (val->front == val->rear) return true;
    else return false;
}

int isQueueFull(Queue* val)
{
    if (val->rear == SIZE_MAX - 1) return true;
    else return false;
}

char enQueue(Queue* val, char data)
{
    if (isQueueFull(val))
    {
        printf("Full Queue !");
        return false;
    }
    else
    {
        val->data[++val->rear] = data;
    }
}

char deQueue(Queue* val)
{
    if (isQueueEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        return val->data[++val->front];
    }
}

char peek(Queue* val)
{
    if (isQueueEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        return val->data[val->front];
    }
}

void printQueue(Queue* val)
{
    printf("Queue [");
    for (int i = (val->front+1); i <= val->rear; i++)
    {
        printf("%c", val->data[i]);

        if (i != (val->rear)) printf(", ");
    }
    printf("]\n");
}