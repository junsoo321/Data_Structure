#include <stdio.h>
#include "listS.h"

int main()
{
    int list[MAX] = { 10, 20, 40, 50, 60, 70 };
    int i, move, size = 6;

    printf("\nBefore Insert\t:");
    for (i = 0; i < size; i++)
    {
        printf("%3d ", list[i]);
    }
    printf("\nElements Count\t: %d\n", size);

    move = insertElement(list, size, 30);

    printf("\nAfter Insert\t:");
    for (i = 0; i <= size; i++)
    {
        printf("%3d ", list[i]);
    }
    printf("\nElements Count\t: %d ", ++size);
    printf("\nMovements Count\t: %d\n", move);

    move = deleteElement(list, size, 30);

    if (move == size)
    {
        printf("\nImpossible to Erase, Empty Element");
    }
    else
    {
        printf("\nAfter Deletion\t:");
        for (i = 0; i < size - 1; i++)
        {
            printf("%3d ", list[i]);
        }

        printf("\nElements Count\t: %d", --size);
        printf("\nMovements Count\t: %d\n", move);
    }

    int key = -1;
    
    while (key != 1)
    {
        printf("\nEnter 1 to Close ... ");
        scanf_s("%d", &key);
    }
    
    return 0;
}