#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现单链表的头插入，并测试：
//
//typedef struct node {
//	int data;
//	struct node* next;
//} Node;
//
//void add_before_head(Node** phead, Node** ptail, int val);
//
//int main(void) {
//	Node* head = NULL;
//	Node* tail = NULL;
//	/* 1.增 */
//	add_before_head(&head, &tail, 1);
//	add_before_head(&head, &tail, 2);
//	add_before_head(&head, &tail, 3);
//	add_before_head(&head, &tail, 4);  // 4 --> 3 --> 2 --> 1
//}
typedef struct node {
	int data;
	struct node* next;
} Node;

void add_before_head(Node** phead, Node** ptail, int val) {
	Node* p = malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	if (*phead == NULL) {
		*ptail = p;
		*phead = p;
		return;
	}
	p->next = (*phead);
	*phead = p;
}


int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	/* 1.增 */
	add_before_head(&head, &tail, 1);
	add_before_head(&head, &tail, 2);
	add_before_head(&head, &tail, 3);
	add_before_head(&head, &tail, 4);  // 4 --> 3 --> 2 --> 1

	return 0;
}