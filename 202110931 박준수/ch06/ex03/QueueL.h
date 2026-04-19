#pragma once

typedef struct queuetype {
	char data;
	struct queue* link;
} queuetype;

typedef struct {
	queuetype* front, * back;
}queue;

queue* cQueue(void);
int isEmpty(queue* que);
void push_back(queue* que, char* c);
char popQueue(queue* que);
char peekQueue(queue* que);
void pQueue(queue* que);
