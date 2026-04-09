#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "QueueC.h"

int main(void) {
	printf("***** 원형 큐 연산 *****\n\n");
	queue* que = cQueue();
	
	printf("삽입 A >>");
	addQueue(que, 'A');
	pQueue(que);
	printf("\n");

	printf("삽입 B >>");
	addQueue(que, 'B');
	pQueue(que);
	printf("\n");

	printf("삽입 C >>");
	addQueue(que, 'C');
	pQueue(que);

	printf("peek item:%c\n\n",peekQueue(que));

	printf("삭제 >> ");
	char c = popQueue(que);
	pQueue(que);
	printf("\t삭제 데이터:%c\n",c);

	printf("삭제 >> ");
	c = popQueue(que);
	pQueue(que);
	printf("\t삭제 데이터:%c\n", c);

	printf("삭제 >> ");
	c = popQueue(que);
	pQueue(que);
	printf("\t삭제 데이터:%c\n", c);

	printf("삽입 D >>");
	addQueue(que, 'D');
	pQueue(que);
	printf("\n");

	printf("삽입 E >>");
	addQueue(que, 'E');
	pQueue(que);
	printf("\n");

	getchar();

	return 0;
}
