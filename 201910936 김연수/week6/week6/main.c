#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "queue.h"
#include "circular_queue.h"
#include "linked_queue.h"
#include "deque.h"

void printMenu()
{
    printf("1. Queue\n");
    printf("2. Circular Queue\n");
    printf("3. Linked Queue\n");
    printf("4. Deque\n");
    printf("0. Exit\n");
    printf("Enter Key : ");
}

void runQueue()
{
    printf("\n[ Queue ]\n");
    Queue* ptr = CreateQueue();

    printf("Insert A >> "); enQueue(ptr, 'A'); printQueue(ptr);
    printf("Insert B >> "); enQueue(ptr, 'B'); printQueue(ptr);
    printf("Insert C >> "); enQueue(ptr, 'C'); printQueue(ptr);
    printf("Insert D >> "); enQueue(ptr, 'D'); printQueue(ptr);
    printf("Insert E >> "); enQueue(ptr, 'E'); printQueue(ptr);
    printf("Insert F >> "); enQueue(ptr, 'F'); printQueue(ptr);

    for (int i = 0; i < 5; i++)
    {
        printf("deQueue >> "); deQueue(ptr); printQueue(ptr);
    }

    free(ptr);
}

void runCircularQueue()
{
    printf("\n[ Circular Queue ]\n");
    CircularQueue* ptr = CreateCircularQueue();

    printf("Insert A >> "); enCircularQueue(ptr, 'A'); printCircularQueue(ptr);
    printf("Insert B >> "); enCircularQueue(ptr, 'B'); printCircularQueue(ptr);
    printf("Insert C >> "); enCircularQueue(ptr, 'C'); printCircularQueue(ptr);
    printf("Insert D >> "); enCircularQueue(ptr, 'D'); printCircularQueue(ptr);
    printf("Insert E >> "); enCircularQueue(ptr, 'E'); printCircularQueue(ptr);
    printf("Insert F >> "); enCircularQueue(ptr, 'F'); printCircularQueue(ptr);

    for (int i = 0; i < 5; i++)
    {
        printf("deQueue >> "); deCircularQueue(ptr); printCircularQueue(ptr);
    }

    printf("Insert G >> "); enCircularQueue(ptr, 'G'); printCircularQueue(ptr);
    printf("Insert H >> "); enCircularQueue(ptr, 'H'); printCircularQueue(ptr);

    free(ptr);
}

void runLinkedQueue()
{
    printf("\n[ Linked Queue ]\n");
    LinkedQueue* ptr = CreateLinkedQueue();

    printf("Insert A >> "); enLinkedQueue(ptr, 'A'); printLinkedQueue(ptr);
    printf("Insert B >> "); enLinkedQueue(ptr, 'B'); printLinkedQueue(ptr);
    printf("Insert C >> "); enLinkedQueue(ptr, 'C'); printLinkedQueue(ptr);
    printf("Insert D >> "); enLinkedQueue(ptr, 'D'); printLinkedQueue(ptr);
    printf("Insert E >> "); enLinkedQueue(ptr, 'E'); printLinkedQueue(ptr);
    printf("Insert F >> "); enLinkedQueue(ptr, 'F'); printLinkedQueue(ptr);

    for (int i = 0; i < 5; i++)
    {
        printf("deQueue >> "); deLinkedQueue(ptr); printLinkedQueue(ptr);
    }

    printf("Insert G >> "); enLinkedQueue(ptr, 'G'); printLinkedQueue(ptr);
    printf("Insert H >> "); enLinkedQueue(ptr, 'H'); printLinkedQueue(ptr);

    destroyLinkedQueue(ptr);
}

void runDeque()
{
    printf("\n[ Deque ]\n");
    Deque* ptr = CreateDeque();

    printf("enqueueRear  A >> "); enqueueRear(ptr, 'A');  printDeque(ptr);
    printf("enqueueRear  B >> "); enqueueRear(ptr, 'B');  printDeque(ptr);
    printf("enqueueRear  C >> "); enqueueRear(ptr, 'C');  printDeque(ptr);

    printf("enqueueFront Z >> "); enqueueFront(ptr, 'Z'); printDeque(ptr);
    printf("enqueueFront Y >> "); enqueueFront(ptr, 'Y'); printDeque(ptr);

    printf("dequeueFront >> "); dequeueFront(ptr); printDeque(ptr);
    printf("dequeueRear  >> "); dequeueRear(ptr);  printDeque(ptr);
    printf("dequeueFront >> "); dequeueFront(ptr); printDeque(ptr);

    free(ptr);
}

int main()
{
    int key;

    while (1)
    {
        printMenu();
        scanf("%d", &key);

        switch (key)
        {
            case 1: 
                runQueue();         
                break;
            case 2: 
                runCircularQueue(); 
                break;
            case 3: 
                runLinkedQueue();   
                break;
            case 4: 
                runDeque();         
                break;
            case 0:
                printf("Exit.\n");
                break;
            default:
                printf("Invalid key. (0~4)\n");
                break;
        }
    }

    return 0;
}
