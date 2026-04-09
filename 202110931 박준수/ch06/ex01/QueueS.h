#pragma once
#define MAX 4

typedef struct queue {
	char element[MAX];
	int front, back;
} queue;

queue* cQueue(void);
int isEmpty(queue* que);
int isFull(queue* que);
void addQueue(queue* que, char* c);
char popQueue(queue* que);
char peekQueue(queue* que);
void pQueue(queue* que);
