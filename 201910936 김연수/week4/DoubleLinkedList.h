#pragma once

typedef struct DoubleLinkNode {
    struct DoubleLinkNode* llink;
    char data[4];
    struct DoubleLinkNode* rlink;
} doubleLinkNode;

typedef struct {
    doubleLinkNode* head;
} doubleLinkNode_h;

doubleLinkNode* createDoubleLinkedList_h(void);
void printDoubleList(doubleLinkNode_h* DL);
void insertDoubleNode(doubleLinkNode_h* DL, doubleLinkNode* pre, char* x);
void deleteDoubleNode(doubleLinkNode_h* DL, doubleLinkNode* old);
doubleLinkNode* searchDoubleNode(doubleLinkNode_h* DL, char* x);