#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "exercises.h"
#include "InsertedLinkedList.h"

int ex4_1(void)
{
    printf("\n");
    printf("=============================\n");
    printf("\tExercise #1\n");
    printf("=============================\n");

    linkedList_h* L;
    L = createLinkedList_h();

    printf("\n(1) Generating New Linked List\n");
    printList(L);

    printf("\n(2) Insert New Node (Wed)\n");
    insertFirstNode(L, "Wed");
    printList(L);

    printf("\n(3) Insert Last Node (Fri)\n");
    insertLastNode(L, "Fri");
    printList(L);

    printf("\n(4) Insert First Node (Mon)\n");
    insertFirstNode(L, "Mon");
    printList(L);

    printf("\n(5) Free Linked List\n");
    freeLinkedList_h(L);
    printList(L);
    
    printf("\nPress Any Key ...");
    getchar();

    return 0;
}