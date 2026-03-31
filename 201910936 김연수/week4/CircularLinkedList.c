#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "CircularLinkedList.h"

circularLinkedList_h* createCircularLinkedList(void)
{
    circularLinkedList_h* CL;
    CL = (circularLinkedList_h*)malloc(sizeof(circularLinkedList_h));
    CL->head = NULL;

    return CL;
}

void printCircularList(circularLinkedList_h* CL)
{
    circularListNode* p;
    printf("CL = (");
    p = CL->head;

    if (p == NULL)
    {
        printf(") \n");
        return;
    }

    do
    {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head)
        {
            printf(", ");
        }
    } while (p != CL->head);

    printf(")\n");

}

void insertFirstCircularNode(circularLinkedList_h* CL, char* x)
{
    circularListNode* newNode, * temp;
    newNode = (circularListNode*)malloc(sizeof(circularListNode));
    
    strcpy(newNode->data, x);

    if (CL->head == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else
    {
        temp = CL->head;

        while (temp->link != CL->head)
        {
            temp = temp->link;
        }

        newNode->link = temp->link;
        temp->link = newNode;
        CL->head = newNode;
    }

}

void insertMiddleCircularNode(circularLinkedList_h* CL, circularListNode* pre, char* x)
{
    circularListNode* newNode;
    newNode = (circularListNode*)malloc(sizeof(circularListNode));
    
    strcpy(newNode->data, x);

    if (CL->head == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else
    {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteCircularNode(circularLinkedList_h* CL, circularListNode* old)
{
    circularListNode* pre;
    if (CL->head == NULL)
    {
        return;
    }
    if (CL->head->link == CL->head)
    {
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL)
    {
        return;
    }
    else
    {
        pre = CL->head;
        
        while (pre->link != old)
        {
            pre = pre->link;
        }

        pre->link = old->link;

        if (old == CL->head)
        {
            CL->head = old->link;
        }

        free(old);
    }
}

circularListNode* searchCircularNode(circularLinkedList_h* CL, char* x)
{
    circularListNode* temp;
    temp = CL->head;

    if (temp == NULL)
    {
        return NULL;
    }
    do
    {
        if (strcmp(temp->data, x) == 0)
        {
            return temp;
        }
        else
        {
            temp = temp->link;
        }
    } while (temp != CL->head);

    return NULL;
}