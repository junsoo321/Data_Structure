#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

//공백 이중 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));	
	DL->head = NULL;		//node가 없는 공백 리스트이므로 head를 NULL로 설정
	return DL;
}

//이중 연결 리스트 순서대로 출력
void printList(linkedList_h* DL) {
	listNode* p;
	printf(" DL = (");
	p = DL->head;

	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

//pre 뒤에 노드 삽입
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (DL->head == NULL) {	//공백 리스트일 경우
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)	//다음 노드 존재 시
			newNode->rlink->llink = newNode;
	}
}

//DL에서 old 노드 삭제
void deleteNode(linkedList_h* DL, listNode* old) {
	if (DL->head == NULL) return;	//DL이 공백 리스트일 경우 return		
	else if (old == NULL) return;	//삭제할 노드 old가 없는 경우 return
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);					//old 해제	 		
	}
}

//리스트에서 x 노드 탐색
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}