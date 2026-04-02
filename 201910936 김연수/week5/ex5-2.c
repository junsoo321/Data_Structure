#include "exercises.h"
#include "stackL.h"

#include <stdio.h>

void ex5_2()
{
    elementL item;
    top = NULL;

    printf("\n== Caculating Linked Stack  ==\n");
    printLinkedStack();

    pushL(1);       printLinkedStack();
    pushL(2);       printLinkedStack();
    pushL(3);       printLinkedStack();

    item = peekL(); printLinkedStack();
    printf("\tpeek => %d", item);

    item = popL();  printLinkedStack();
    printf("\tpop => %d", item);

    item = popL();  printLinkedStack();
    printf("\tpop => %d", item);

    item = popL();  printLinkedStack();
    printf("\tpop => %d\n", item);

    printf("Press Any Key ...");
    getchar();

    return;
}