#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

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

//리스트에서 노드 p 삭제
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;								//삭제할 노드의 앞 노드를 나타낼 포인터
	if (L->head == NULL) return;				//공백 리스트일 경우 return
	if (L->head->link == NULL) {				//리스트에 노드가 1개뿐일 경우
		free(L->head);							//첫 노드 해제
		L->head = NULL;						//리스트 시작 포인터 NULL로 설정
		return;
	}
	else if (p == NULL) return;				//삭제할 노드가 없으면 return
	else {											//pre의 링크 필드가 삭제할 노드 p를 가리키게 될 때까지 반복(=p 앞노드 위치 찾기)
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;					//찾은 pre가 p의 다음 노드를 가리키도록 변경(p가 연결에서 빠져나가도록)
		free(p);									//p 해제
	}
}

//리스트에서 x노드 탐색
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {		//x와 데이터필드가 같은 노드면 반환, 다르면 다음 노드로 넘어감
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

//리스트 노드 순서를 역순으로 변환
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;	//p를 첫 노드를 가리키도록 함
	q = NULL;
	r = NULL;

	while (p != NULL) {	//첫 노드부터 하나씩 다음 노드로 이동하면서 노드 간 연결 변경
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}