#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "exercises.h"
#include "CircularLinkedList.h"

int ex4_3()
{
    printf("\n");
    printf("=============================\n");
    printf("\tExercise #3\n");
    printf("=============================\n");

    circularLinkedList_h* CL;
    circularListNode* p;

    CL = createCircularLinkedList();
    printf("\n(1) Generating New Circular Linked List\n");
    printCircularList(CL);

    printf("\n(2) Insert (Mon) Node\n");
    insertFirstCircularNode(CL, "Mon");
    printCircularList(CL);

    printf("\n(3) Insert (Wed) Node After (Mon) Node\n");
    p = searchCircularNode(CL, "Mon");
    insertMiddleCircularNode(CL, p, "Wed");
    printCircularList(CL);

    printf("\n(4) Insert (Fri) Node After (Wed) Node\n");
    p = searchCircularNode(CL, "Wed");
    insertMiddleCircularNode(CL, p, "Fri");
    printCircularList(CL);

    printf("\n(5) Delete (Wed) Node\n");
    p = searchCircularNode(CL, "Wed");
    deleteCircularNode(CL, p);
    printCircularList(CL);

    printf("\nPress Any Key ...");
    getchar();

    return 0;
}