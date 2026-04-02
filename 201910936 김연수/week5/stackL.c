#include <stdlib.h>

#include "stackL.h"

int isLinkedStackEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pushL(elementL item)
{
    linkedStackNode* temp = (linkedStackNode*)malloc(sizeof(linkedStackNode));

    temp->data = item;
    temp->link = top;

    top = temp;
}

elementL popL()
{
    elementL item;
    linkedStackNode* temp = top;

    if (isLinkedStackEmpty())
    {
        printf("\n\nStack is Empty !\n");
        return 0;
    }
    else
    {
        item = temp->data;
        top = temp->link;
        free(temp);

        return item;
    }
}

elementL peekL()
{
    if (isLinkedStackEmpty())
    {
        printf("\n\nStack is Empty !\n");
        return 0;
    }
    else
    {
        return(top->data);
    }
}

void printLinkedStack()
{
    linkedStackNode* p = top;
    printf("\nSTACK [ ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("]");
}