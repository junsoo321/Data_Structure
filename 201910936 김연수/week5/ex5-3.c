#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "exercises.h"
#include "stackString.h"

void ex5_3()
{
    printf("\n==    Open Pair Analysis    ==\n");
    (void) scanf("%s", string);

    for (int i = 0; i < STRING_MAX; i++)
    {
        if (string[i] == NULL)
        {
            stringTop = i;
            break;
        }

        printf("\n* %c", string[i]);
    }
}