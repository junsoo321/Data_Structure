#pragma once

typedef int elementL;

typedef struct linkedStackNode {
    elementL data;
    struct linkedStackNode* link;
} linkedStackNode;

linkedStackNode* top;

int isLinkedStackEmpty();
void pushL(elementL item);
elementL popL();
elementL peekL();
void printLinkedStack();