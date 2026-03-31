#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "exercises.h"
#include "InsertedLinkedList.h"

int ex4_2()
{
    linkedList_h* L;
    listNode* p;
    L = createLinkedList_h();

    printf("(1) Insert Last Node (Mon), (Wed), (Fri)");
    insertLastNode(L, "Mon");
    insertLastNode(L, "Wed");
    insertLastNode(L, "Fri");

}