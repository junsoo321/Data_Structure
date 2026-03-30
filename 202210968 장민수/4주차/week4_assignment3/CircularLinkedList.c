#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

//공백 원형 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL; //node가 없는 공백 리스트이므로 head를 NULL로 설정
	return CL;
}

//연결 리스트 순서대로 출력
void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL = (");
	p = CL->head;

	if (p == NULL) {
		printf(") \n"); return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

//첫번째 노드 삽입
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당
	strcpy(newNode->data, x);		//새 노드 데이터필드에 x 저장

	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

//pre 뒤에 노드 삽입
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//pre 뒤에 있는 노드 old 삭제
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;					//삭제할 노드 바로 앞 노드 나타내는 포인터
	if (CL->head == NULL) return;	//CL이 공백리스트일 경우 return
	if (CL->head->link == CL->head) {	//CL의 노드가 한 개인 경우
		free(CL->head);						//첫 번째 노드 해제
		CL->head = NULL;					//리스트 시작 포인터 NULL로 설정
		return;
	}
	else if (old == NULL) return;			//삭제할 노드 old가 없을 경우 return
	else {
		pre = CL->head;					//pre를 리스트 시작 노드에 연결
		while (pre->link != old) {
			pre = pre->link;					//pre로 old의 바로 앞 노드 찾기
		}
		pre->link = old->link;				//old 바로 앞 노드와 뒤 노드 연결
		if (old == CL->head)
			CL->head = old->link;
		free(old);								//old 해제
	}
}

//원형 연결 리스트에서 x노드 탐색
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) return NULL;
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	} while (temp != CL->head);
	return NULL;
}