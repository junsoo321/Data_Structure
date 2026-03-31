#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "DoubleLinkedList.h"

doubleLinkNode* createDoubleLinkedList_h(void)
{
    doubleLinkNode_h* DL;
    
    DL = (doubleLinkNode_h*)malloc(sizeof(doubleLinkNode_h));
    DL->head = NULL;
    
    return DL;
}

void printDoubleList(doubleLinkNode_h* DL)
{
    doubleLinkNode* p;
    printf("DL = (");
    
    p = DL->head;

    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL)
        {
            printf(", ");
        }
    }

    printf(")\n");
}

void insertDoubleNode(doubleLinkNode_h* DL, doubleLinkNode* pre, char* x)
{
    doubleLinkNode* newNode;

    newNode = (doubleLinkNode*)malloc(sizeof(doubleLinkNode));
    strcpy(newNode->data, x);

    if (DL->head == NULL)
    {
        newNode->rlink = NULL;
        newNode->llink = NULL;
        DL->head = newNode;
    }
    else
    {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if (newNode->rlink != NULL)
        {
            newNode->rlink->llink = newNode;
        }
    }

}

void deleteDoubleNode(doubleLinkNode_h* DL, doubleLinkNode* old)
{
    if (DL->head == NULL)
    {
        return;
    }
    else if (old == NULL)
    {
        return;
    }
    else
    {
        old->llink->rlink = old->rlink;
        old->rlink->llink = old->llink;
        free(old);
    }
}

doubleLinkNode* searchDoubleNode(doubleLinkNode_h* DL, char* x)
{
    doubleLinkNode* temp;
    temp = DL->head;
    
    while (temp != NULL)
    {
        if (strcmp(temp->data, x) == 0)
        {
            return temp;
        }
        else
        {
            temp = temp->rlink;
        }
    }

    return temp;
}