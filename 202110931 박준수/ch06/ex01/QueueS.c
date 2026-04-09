#include <stdio.h>
#include <stdlib.h>
#include "QueueS.h"

queue* cQueue(void) {
	queue* que = (queue*)malloc(sizeof(queue));
	que->front = -1;
	que->back = -1;
	return que;
}

int isEmpty(queue* que) {
	return (que->front == que->back) ? 1 : 0;
}

int isFull(queue* que) {
	return (que->back >= MAX-1) ? 1 : 0;
}

void errorPrint(char c) {
	if (c=='f')
		printf("Queue is FULL!");
	else
		printf("Queue is Empty!");
}

void addQueue(queue* que, char* c) {
	if (isFull(que)) {
		errorPrint('f');
		return;
	}
	que->back++;
	que->element[que->back] = c;
}

char popQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint('e');
		return;
	}
	que->front++;
	return que->element[que->front];
}

char peekQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint('e');
		return;
	}
	return que->element[que->front+1];
}

void pQueue(queue* que) {
	printf(" Queue:[ ");
	for (int i = que->front+1;i <= que->back;i++)
		printf("%c ", que->element[i]);
	printf("]");
}
