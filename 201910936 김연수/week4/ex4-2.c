#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "exercises.h"
#include "InsertedLinkedList.h"

int ex4_2()
{
    printf("\n");
    printf("=============================\n");
    printf("\tExercise #2\n");
    printf("=============================\n");

    linkedList_h* L;
    listNode* p;
    L = createLinkedList_h();

    printf("\n(1) Insert Last Node (Mon), (Wed), (Sun)\n");
    insertLastNode(L, "Mon");
    insertLastNode(L, "Wed");
    insertLastNode(L, "Sun");
    printList(L);

    printf("\n(2) Search for (Wed) Node\n");
    p = searchNode(L, "Wed");
    if (p == NULL)
    {
        printf("No such node in the list.\n");
    }
    else
    {
        printf("Node found - %s\n", p->data);
    }

    printf("\n(3) Insert (Fri) Node After (Wed)\n");
    insertMiddleNode(L, p, "Fri");
    printList(L);

    printf("\n(4) Delete (Sun) Node From List\n");
    p = searchNode(L, "Sun");
    deleteNode(L, p);
    printList(L);

    printf("\n(5) Reverse Entire List\n");
    reverse(L);
    printList(L);

    freeLinkedList_h(L);
    printf("\nPress Any Key ...");
    getchar();

    return 0;
}