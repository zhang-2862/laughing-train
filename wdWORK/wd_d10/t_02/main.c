#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现单链表的尾插法，并测试：
//
//typedef struct node {
//	int data;
//	struct node* next;
//} Node;
//
//void add_behind_tail(Node** phead, Node** ptail, int val);
//
//int main(void) {
//	Node* head = NULL;
//	Node* tail = NULL;
//	/* 1.增 */
//	add_behind_tail(&head, &tail, 1);
//	add_behind_tail(&head, &tail, 2);
//	add_behind_tail(&head, &tail, 3);
//	add_behind_tail(&head, &tail, 4);  // 1 --> 2 --> 3 --> 4
//
//	return 0;
//}

typedef struct node {
	int data;
	struct node* next;
} Node;

void add_behind_tail(Node** phead, Node** ptail, int val) {
	Node* p = malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	if (*phead == NULL) {
		*phead = p;
		*ptail = p;
		return;
	}
	(*ptail)->next = p;
	*ptail = p;
}

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	/* 1.增 */
	add_behind_tail(&head, &tail, 1);
	add_behind_tail(&head, &tail, 2);
	add_behind_tail(&head, &tail, 3);
	add_behind_tail(&head, &tail, 4);  // 1 --> 2 --> 3 --> 4

	return 0;
}