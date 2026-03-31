#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void printList(linkedList_h* L) {
	listNode* p;
	printf("CL = (");
	p = L->head;
	
	if (p == NULL) {
		printf(") \n");
		return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != L->head) 
			printf(", ");
	} while (p != L->head);
	printf(") \n");
}

void insertFirstNode(linkedList_h* L, const char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = L->head;
		while (temp->link != L->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;
		L->head = newNode;
	}
}

void insertMiddleNode(linkedList_h* L, listNode* pre, const char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL) { 
		free(L->head);			
		L->head = NULL;			
		return;
	}
	else if (p == NULL) return;		
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		if (p == L->head)
			L->head = p->link;
		free(p);
	}
}

listNode* searchNode(linkedList_h* L, const char* x) {
	listNode* temp;
	temp = L->head;
	if (temp == NULL) return NULL;
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	} while (temp != L->head);
	return NULL;
}
