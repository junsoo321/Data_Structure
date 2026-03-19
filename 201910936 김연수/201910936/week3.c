#include "week3.h"

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

const int WEEK3_START  = 0;
const int WEEK3_END    = 7;

// forward declare
int factorial(int val);

const int hasKey(const int key)
{
    if (key >= WEEK3_START && key <= WEEK3_END) return true;
    else return false;
}

void pointer()
{
    int key = -1;

    printf("Exercise Week 3\n\n");

    printf("============================\n");
    printf("#0 : Exit\n");
    printf("#1 : Integer Pointer\n");
    printf("#2 : Char Pointer\n");
    printf("#3 : String Size\n");
    printf("#4 : Multi-Dimensional Array\n");
    printf("#5 : Student Array\n");
    printf("#6 : Struct Definition\n");
    printf("#7 : Factorial Function\n");
    printf("============================\n\n");

    printf("Enter Exercise Number : ");
    scanf_s("%d", &key);


    while (hasKey(key) == false)
    {
        printf("Wrong Key! Enter Again :");
        scanf_s("%d", &key);
    }

    switch (key)
    {
    case 0:
    {
        printf("Terminating Program ... Good Bye !");
    }
        return;

    case 1:
    {
        int pointedInt = 100;
        int* pointerInt = &pointedInt;

        printf("Pointed : %d\t Address : %p", *pointerInt, &pointedInt);
    }
    break;

    case 2:
    {
        char pointedChar[3][10] = { "Dreams", "Come", "True!" };
        const char* pointerChar[3] = { {"Dreams"}, {"Come"}, {"True!"} };

        char* cacheChar[4][50];

        for (int i = 0; i < 4; i++)
        {
            printf("#%d\t :", i + 1);
            scanf_s("%s", cacheChar[i], 50);
        }
    }
    break;

    case 3:
    {
        char inputString[50];
        printf("Enter String : ");
        scanf_s("%s", inputString, 50);

        printf("String Size : %d", strlen(inputString));
    }
    break;

    case 4:
    {
        int array[2][3][4];

        int current = 1;
        int maximum = 2 * 3 * 4;

        for (int first = 0; first < 2; first++)
        {
            for (int second = 0; second < 3; second++)
            {
                for (int third = 0; third < 4; third++)
                {
                    printf("Enter Input(%d/%d) : ", current++, maximum);
                    scanf_s("%d", &array[first][second][third]);
                }
            }
        }

        for (int first = 0; first < 2; first++)
        {
            for (int second = 0; second < 3; second++)
            {
                for (int third = 0; third < 4; third++)
                {
                    printf("Array[%d][%d][%d] : %d\n", first, second, third, array[first][second][third]);
                }
            }
        }

    }
    break;

    case 5:
    {
        char inputArray[2][3][50];  // each data can contain up to 50

        for (int x  = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                const char* currentIndex = "";

                switch (y)
                {
                case 0: currentIndex = "name"; break;
                case 1: currentIndex = "major"; break;
                case 2: currentIndex = "student id"; break;
                }
                printf("Student #%d's %s : ", x+1, currentIndex);
                scanf_s("%s", inputArray[x][y], 50);
            }
        }

        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                const char* currentIndex = "";

                switch (y)
                {
                case 0: currentIndex = "name"; break;
                case 1: currentIndex = "major"; break;
                case 2: currentIndex = "student id"; break;
                }

                printf("Student #%d's %s : %s\n", x+1, currentIndex, inputArray[x][y]);
            }
        }
    }
    break;

    case 6:
    {
        struct employee {
            char name[10];
            int year;
            int pay;
        };

        struct employee slave = { "poor-guy", 100, 2000000 };
        printf("struct employee name : %s year : %d pay : %d", slave.name, slave.year, slave.pay);
    }
    break;

    case 7:
    {
        int value;
        printf("Enter Input : ");
        scanf_s("%d", &value);

        int result = factorial(value);

        printf("Factorial %d : %d \n", value, result);
    }

    break;

    default:
        printf("Wrong Key Number");
        break;

    }
}

int factorial(int val)
{
    printf("Factorial[%d] Called !\n", val);
    if (val == 1)
    {
        return val;
    }
    else
    {
        return val * factorial(val-1);
    }
}