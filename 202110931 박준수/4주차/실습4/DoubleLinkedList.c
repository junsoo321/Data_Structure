#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void printList(linkedList_h* L) {
	listNode* p;
	printf("DL = (");
	p = L->head;
	
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertNode(linkedList_h* L, listNode* pre, const char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	if (L->head == NULL) return;	
	else if (p == NULL) return;
	else {
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		free(p);		
	}
}

listNode* searchNode(linkedList_h* L, const char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}
