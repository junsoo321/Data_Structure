#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "QueueD.h"

int main(void) {
	printf("***** 데크 연산 *****\n\n");
	queue* que = cQueue();
	
	printf("front 삽입 A >>");
	push_front(que, 'A');
	pQueue(que);
	printf("\n");

	printf("front 삽입 B >>");
	push_front(que, 'B');
	pQueue(que);
	printf("\n");

	printf("rear  삽입 C >>");
	push_back(que, 'C');
	pQueue(que);
	printf("\n");

	printf("front 삭제 >> ");
	char c = pop_front(que);
	pQueue(que);
	printf("\t삭제 데이터:%c\n",c);

	printf("rear  삭제 >> ");
	c = pop_back(que);
	pQueue(que);
	printf("\t삭제 데이터:%c\n", c);

	printf("rear  삽입 D >>");
	push_back(que, 'D');
	pQueue(que);
	printf("\n");

	printf("front 삽입 E >>");
	push_front(que, 'E');
	pQueue(que);
	printf("\n");

	printf("front 삽입 F >>");
	push_front(que, 'F');
	pQueue(que);
	printf("\n");

	printf("peek Front item:%c\n", peek_front(que));
	printf("peek Rear item:%c\n", peek_back(que));

	getchar();

	return 0;
}
