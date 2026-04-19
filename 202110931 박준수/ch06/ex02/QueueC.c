#include <stdio.h>
#include <stdlib.h>
#include "QueueC.h"

queue* cQueue(void) {
	queue* que = (queue*)malloc(sizeof(queue));
	que->front = 0;
	que->back = 0;
	return que;
}

int isEmpty(queue* que) {
	return (que->front == que->back) ? 1 : 0;
}

int isFull(queue* que) {
	return ((que->back+1)%MAX==que->front) ? 1 : 0;
}

void errorPrint(char c) {
	if (c=='f')
		printf("Circular Queue is FULL!");
	else
		printf("Circular Queue is Empty!");
}

void push_back(queue* que, char* c) {
	if (isFull(que)) {
		errorPrint('f');
		return;
	}
	que->back++;
	que->back %= MAX;
	que->element[que->back] = c;
}

char popQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint('e');
		return;
	}
	que->front++;
	que->front %= MAX;
	return que->element[que->front];
}

char peekQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint('e');
		return;
	}
	return que->element[(que->front+1)%MAX];
}

void pQueue(queue* que) {
	printf(" Circular Queue:[ ");
	for (int i = (que->front + 1) % MAX; i != (que->back+1) % MAX; i = (i + 1) % MAX)
		printf("%c ", que->element[i]);
	printf("]");
}
