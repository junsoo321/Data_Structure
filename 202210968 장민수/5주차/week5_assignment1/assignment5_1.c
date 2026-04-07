#include <stdio.h>
#include "stackS.h"

int main(void) {
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1);	printStack();
	push(2);	printStack();
	push(3);	printStack();

	item = peek();	printStack();
	printf("peek => %d", item);

	item = pop();	printStack();
	printf("\t pop => %d", item);

	item = pop();	printStack();
	printf("\t pop => %d", item);

	item = pop();	printStack();
	printf("\t pop => %d\n", item);

	getchar(); return 0;
}