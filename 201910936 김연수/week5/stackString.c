#include "stackS.h"

#include <stdio.h>
#include "stackString.h"

int isStringEmpty()
{
    if (stringTop == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

letter popString()
{
    if (isStackEmpty())
    {
        printf("\n\nStack is Empty!\n");
        return 0;
    }
    else
    {
        return stack[stringTop--];
    }
}

void printString()
{
    int i;
    printf("\nSTRING [ ");

    for (i = 0; i <= stringTop; i++)
    {
        printf("%d ", string[i]);
    }

    printf("]");
}