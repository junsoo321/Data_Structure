#pragma once

typedef struct ListNode {
	char data[4];
	struct ListNode* llink;
	struct ListNode* rlink;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertNode(linkedList_h* L, listNode* pre, const char* x);
void deleteNode(linkedList_h* L, listNode* p);
listNode* searchNode(linkedList_h* L, const char* x);
