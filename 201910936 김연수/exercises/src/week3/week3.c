#include <week3/week3.h>

#include <common/common.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int WEEK3_START  = 0;
const int WEEK3_END    = 7;

// forward declare
const int menu();
const int operate(const int);
int factorial(int);

static const int hasKey(const int key)
{
    if (key >= WEEK3_START && key <= WEEK3_END) return true;
    else return false;
}

void week3()
{
    const int* key = menu();

    while (operate(key) == true)
    {
        key = menu();
    }

    return;
}

static const int menu()
{
    line();

    printf("#0 : Exit\n");
    printf("#1 : Integer Pointer\n");
    printf("#2 : Char Pointer\n");
    printf("#3 : String Size\n");
    printf("#4 : Multi-Dimensional Array\n");
    printf("#5 : Student Array\n");
    printf("#6 : Struct Definition\n");
    printf("#7 : Factorial Function\n");

    line();

    int key = getInt("Exercise Number");

    while (hasKey(key) == false)
    {
        printf("Wrong Key! Enter Again :");
        scanf_s("%d", &key);
    }

    return key;
}

static const int operate(const int key)
{
    line();

    switch (key)
    {
    case 0:
    {
        printf("Terminating Program ... Good Bye !");
    }
    return false;

    case 1:
    {
        int pointedInt = 100;
        int* pointerInt = &pointedInt;

        printf("Pointed : %d\t Address : %p\n", *pointerInt, &pointedInt);
    }
    break;

    case 2:
    {
        char pointedChar[3][10] = { "Dreams", "Come", "True!" };
        const char* pointerChar[3] = { {"Dreams"}, {"Come"}, {"True!"} };

        char* cacheChar[4];

        for (int i = 0; i < 4; i++)
        {
            cacheChar[i] = (char*)malloc(BUFFER_SIZE * sizeof(char));

            printf("#%d\t : ", i + 1);
            scanf_s("%s", cacheChar[i], BUFFER_SIZE);
        }

        line();

        printf("Saved As ... \n");

        for (int i = 0; i < 4; i++)
        {
            printf("#%d\t : %s\n", i + 1, cacheChar[i]);
        }

    }
    break;

    case 3:
    {
        char* inputString = getChar("String", BUFFER_SIZE);
        printf("String Size\t: %d\n", strlen(inputString));
        free(inputString);
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
                printf("Student #%d's %s : ", x + 1, currentIndex);
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

                printf("Student #%d's %s : %s\n", x + 1, currentIndex, inputArray[x][y]);
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
        printf("struct employee Initialized\nname\t: %s\nyear\t: %d\npay\t: %d\n", slave.name, slave.year, slave.pay);
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

    line();

    return true;
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