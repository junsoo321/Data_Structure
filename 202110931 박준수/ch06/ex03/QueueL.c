#include <stdio.h>
#include <stdlib.h>
#include "QueueL.h"

queue* cQueue(void) {
	queue* que;
	que = (queue*)malloc(sizeof(queue));
	que->front = NULL;
	que->back = NULL;
	return que;
}

int isEmpty(queue* que) {
	return (que->front == NULL) ? 1 : 0;
}

void errorPrint() {
	printf("Linked Queue is Empty!");
}

void push_back(queue* que, char* c) {
	queuetype* newnode = (queuetype*)malloc(sizeof(queuetype));
	newnode->data = c;
	newnode->link = NULL;
	if (que->front == NULL) {
		que->front = newnode;
		que->back = newnode;
	}
	else {
		que->back->link = newnode;
		que->back = newnode;
	}
}

char popQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	queuetype* old = que->front;
	char c;
	c = old->data;
	que->front = que->front->link;
	if (que->front == NULL)
		que->back = NULL;
	free(old);
	return c;
}

char peekQueue(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	return que->front->data;
}

void pQueue(queue* que) {
	queuetype* temp = que->front;
	printf(" Linked Queue:[ ");
	while (temp) {
		printf("%c ", temp->data);
		temp = temp->link;
	}
	printf("]");
}
