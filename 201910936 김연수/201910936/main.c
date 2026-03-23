#include "week2.h"
#include "week3.h"

#include <stdio.h>

int main()
{
    int week = -1;
    printf("Enter Week : ");
    scanf_s("%d", &week);

    switch (week)
    {
    case 2:
        break;
    case 3:
        pointer();
        break;
    default:
        printf("Undefined Week : %d", week);
        break;
    }

    return 0;
}