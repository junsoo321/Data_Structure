#include "common.h"

#include "../../week3/week3.h"

#include <stdio.h>
#include <stdlib.h>

void line()
{
    printf("============================\n");
}

int getInt(char* label)
{
    int res;
    printf("Enter %s\t: ", label);
    scanf_s("%d", &res);

    return res;
}

char* getChar(char* label, const int size)
{
    char* res = (char*)malloc(size * sizeof(char));

    printf("Enter %s\t: ", label);
    scanf_s("%s", res, size);

    return res;
}

void run(const int number)
{
    struct week current;
    current.number = number;

    switch (current.number)
    {
    case 3:
        current.operate = week3;
        break;

    default:
        printf("Invalid Fallthrough !");
        break;
    }

    current.operate();
}