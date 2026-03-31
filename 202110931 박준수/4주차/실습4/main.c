#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DoubleLinkedList.h"

int main(void) {
	linkedList_h* L;
	listNode* p;

	L = createLinkedList_h();  // 공백 리스트 생성
	printf("(1) 이중 연결 리스트 생성하기! \n");
	printList(L);

	printf("\n(2) 이중 연결 리스트에 [월] 노드 삽입하기! \n");
	insertNode(L, NULL, "월");
	printList(L);

	printf("\n(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(L, "월");
	insertNode(L, p, "수");
	printList(L);

	printf("\n(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(L, "수");
	insertNode(L, p, "금");
	printList(L);

	printf("\n(5) 이중 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(L, "수");
	deleteNode(L, p);
	printList(L);
	getchar();

	return 0;
}
