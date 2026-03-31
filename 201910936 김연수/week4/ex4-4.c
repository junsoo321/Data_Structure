#include <stdlib.h>

#include "exercises.h"
#include "DoubleLinkedList.h"

int ex4_4()
{
    printf("\n");
    printf("=============================\n");
    printf("\tExercise #4\n");
    printf("=============================\n");

    doubleLinkNode_h* DL;
    doubleLinkNode* p;

    DL = createDoubleLinkedList_h();

    printf("\n(1) Generating New Linked List\n");
    printDoubleList(DL);

    printf("\n(2) Insert (Mon) Node\n");
    insertDoubleNode(DL, NULL, "Mon");
    printDoubleList(DL);

    printf("\n(3) Insert (Wed) Node After (Mon) Node\n");
    p = searchDoubleNode(DL, "Mon");
    insertDoubleNode(DL, p, "Wed");
    printDoubleList(DL);

    printf("\n(4) Insert (Fri) Node After (Wed) Node\n");
    p = searchDoubleNode(DL, "Wed");
    insertDoubleNode(DL, p, "Fri");
    printDoubleList(DL);

    printf("\n(5) Delete (Wed) Node\n");
    p = searchDoubleNode(DL, "Wed");
    deleteDoubleNode(DL, p);
    printDoubleList(DL);

    printf("\nPress Any Key ...");
    getchar();

    return 0;
}