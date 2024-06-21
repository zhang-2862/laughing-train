#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现单链表的顺序插入，并测试：
//
//typedef struct node {
//	int data;
//	struct node* next;
//} Node;
//
//void add_in_sort(Node** phead, Node** ptail, int val);
//
//int main(void) {
//	Node* head = NULL;
//	Node* tail = NULL;
//	/* 1.增 */
//	add_in_sort(&head, &tail, 9);
//	add_in_sort(&head, &tail, 5);
//	add_in_sort(&head, &tail, 2);
//	add_in_sort(&head, &tail, 7);  // 2 --> 5 --> 9 --> 7
//
//	return 0;
//}

typedef struct node {
	int data;
	struct node* next;
} Node;

void add_in_sort(Node** phead, Node** ptail, int val) {
	Node* p = malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	if (*phead == NULL) {
		*phead = p;
		*ptail = p;
		return;
	}
	if ((*phead)->data <= val) {
		p->next = *phead;
		*phead = p;
		return;
	}
	if ((*ptail)->data >= val) {
		(*ptail)->next = p;
		*ptail = p;
		return;
	}
	Node* cur = *phead;
	while (cur->next)
	{
		if (cur->next->data < val) {
			break;
		}
		cur = cur->next;
	}
	p->next = cur->next;
	cur->next = p;
}

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	/* 1.增 */
	add_in_sort(&head, &tail, 9);
	add_in_sort(&head, &tail, 5);
	add_in_sort(&head, &tail, 2);
	add_in_sort(&head, &tail, 7);  // 2 --> 5 --> 9 --> 7

	return 0;
}
