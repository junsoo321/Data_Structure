#pragma once

typedef struct queuetype {
	char data;
	struct queue* llink;
	struct queue* rlink;
} queuetype;

typedef struct {
	queuetype* front, * back;
}queue;

queue* cQueue(void);
int isEmpty(queue* que);
void push_front(queue* que, char* c);
void push_back(queue* que, char* c);
char pop_front(queue* que);
char pop_back(queue* que);
char peek_front(queue* que);
char peek_back(queue* que);
void pQueue(queue* que);
