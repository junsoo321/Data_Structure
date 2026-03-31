#pragma once

typedef struct CircularListNode {
    char data[4];
    struct CircularListNode* link;
} circularListNode;

typedef struct {
    circularListNode* head;
} circularLinkedList_h;

circularLinkedList_h* createCircularLinkedList(void);
void printCircularList(circularLinkedList_h* CL);
void insertFirstCircularNode(circularLinkedList_h* CL, char* x);
void insertMiddleCircularNode(circularLinkedList_h* CL, circularListNode* pre, char* x);
void deleteCircularNode(circularLinkedList_h* CL, circularListNode* old);
circularListNode* searchCircularNode(circularLinkedList_h* CL, char* x);