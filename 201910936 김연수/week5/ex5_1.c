#include <stdio.h>
#include "stackS.h"

void ex5_1()
{
    element item;
    printf("\n== Calculating Linear Stack ==\n");

    printStack();

    push(1);        printStack();
    push(2);        printStack();
    push(3);        printStack();

    item = peek();  printStack();
    printf("\tpeek => %d", item);

    item = pop();   printStack();
    printf("\tpop => %d", item);

    item = pop(); printStack();
    printf("\tpop => %d", item);

    item = pop(); printStack();
    printf("\tpop => %d\n", item);

    printf("Press Any Key ...");
    getchar();

    return;
}