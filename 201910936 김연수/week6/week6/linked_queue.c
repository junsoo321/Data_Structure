#include "linked_queue.h"

#include <stdio.h>

LinkedQueue* CreateLinkedQueue()
{
    LinkedQueue* res = (LinkedQueue*)malloc(sizeof(LinkedQueue));

    res->front = NULL;
    res->rear = NULL;
    res->size = 0;

    return res;
}

int isLinkedQueueEmpty(LinkedQueue* val)
{
    if (val->front == NULL) return true;
    else return false;
}

char enLinkedQueue(LinkedQueue* val, char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = val->rear;

    if (isLinkedQueueEmpty(val))
    {
        val->front = newNode;
        val->rear = newNode;
    }
    else
    {
        val->rear->next = newNode;
        val->rear = newNode;
    }

    val->size++;
    return data;
}

char deLinkedQueue(LinkedQueue* val)
{
    if (isLinkedQueueEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        Node* target = val->front;
        char res = target->data;

        val->front = target->next;

        if (val->front != NULL)
            val->front->prev = NULL;
        else
            val->rear = NULL;

        free(target);
        val->size--;
        return res;
    }
}

char peekLinkedQueue(LinkedQueue* val)
{
    if (isLinkedQueueEmpty(val))
    {
        printf("Empty Queue !");
        return false;
    }
    else
    {
        return val->front->data;
    }
}

void printLinkedQueue(LinkedQueue* val)
{
    printf("LinkedQueue [");

    Node* cur = val->front;
    while (cur != NULL)
    {
        printf("%c", cur->data);

        if (cur->next != NULL) printf(", ");
        cur = cur->next;
    }

    printf("]\n");
}

void destroyLinkedQueue(LinkedQueue* val)
{
    Node* cur = val->front;
    while (cur != NULL)
    {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(val);
}
