#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "InsertLinkedList.h"

//공백 리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL; //node가 없는 공백 리스트이므로 head를 NULL로 설정
	return L;
}

//연결 리스트의 전체 메모리 해제
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link; //기존 head가 가리키던 주소를 다음 node로 바꿈
		free(p); //기존 첫 node 메모리 해제 및 NULL로 초기화
		p = NULL;
	}
}

//연결 리스트 순서대로 출력
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

//첫 번째 노드로 삽입
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당
	strcpy(newNode->data, x);							//새 노드 데이터필드에 x 저장
	newNode->link = L->head;
	L->head = newNode;
}

//새 노드를 pre노드 뒤에 삽입
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {				//L이 공백 리스트일 경우
		newNode->link = NULL;		//새 노드 link를 NULL로 설정(마지막 노드로 설정)
		L->head = newNode;
	}
	else if (pre == NULL) {				//삽입위치 pre가 NULL일 경우
		newNode->link = L->head;
		L->head = newNode;			//새 노드를 첫 번째 노드로 삽입
	}
	else {
		newNode->link = pre->link;	//pre의 링크 필드가 가리키던 주소를 새 노드가 받음
		pre->link = newNode;			//pre노드는 새 노드를 가리키면서 노드 삽입됨
	}
}

//마지막 노드로 삽입
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {		//리스트가 공백인 경우
		L->head = newNode;	//새 노드를 첫 번째 노드로 연결 후 return
		return;
	}
	//공백이 아닐 경우
	temp = L->head;
	while (temp->link != NULL) temp = temp->link; //temp가 마지막 노드가 될 때까지 쭉 찾기
	temp->link = newNode;							//새 노드를 temp의 다음 노드로 연결
}