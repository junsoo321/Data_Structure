#include <stdio.h>
#include <stdlib.h>
#include "QueueD.h"

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
	printf("Linked deQue is empty!\n");
}

void push_front(queue* que, char* c) {
	queuetype* newnode = (queuetype*)malloc(sizeof(queuetype));
	newnode->data = c;
	if (isEmpty(que)) {
		que->front = newnode;
		que->back = newnode;
		newnode->llink = NULL;
		newnode->rlink = NULL;
	}
	else {
		que->front->llink = newnode;
		newnode->rlink = que->front;
		newnode->llink = NULL;
		que->front = newnode;
	}
}

void push_back(queue* que, char* c) {
	queuetype* newnode = (queuetype*)malloc(sizeof(queuetype));
	newnode->data = c;
	if (isEmpty(que)) {
		que->front = newnode;
		que->back = newnode;
		newnode->llink = NULL;
		newnode->rlink = NULL;
	}
	else {
		que->back->rlink = newnode;
		newnode->rlink = NULL;
		newnode->llink = que->back;
		que->back = newnode;
	}
}

char pop_front(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	queuetype* old = que->front;
	char c;
	c = old->data;
	if (que->front->rlink == NULL) {
		que->front = NULL;
		que->back = NULL;
	}
	else {
		que->front = que->front->rlink;
		que->front->llink = NULL;
	}
	free(old);
	return c;
}

char pop_back(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	queuetype* old = que->back;
	char c;
	c = old->data;
	if (que->back->llink == NULL) {
		que->front = NULL;
		que->back = NULL;
	}
	else {
		que->back = que->back->llink;
		que->back->rlink = NULL;
	}
	free(old);
	return c;
}

char peek_front(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	return que->front->data;
}

char peek_back(queue* que) {
	if (isEmpty(que)) {
		errorPrint();
		return;
	}
	return que->back->data;
}

void pQueue(queue* que) {
	queuetype* temp = que->front;
	printf(" DeQue:[ ");
	while (temp) {
		printf("%c ", temp->data);
		temp = temp->rlink;
	}
	printf("]");
}
