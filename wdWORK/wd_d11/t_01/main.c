#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//求链表中间结点(876. 链表的中间结点)
//
//给定单链表的第一个结点 head ，请你找出并返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
//
//struct ListNode* middleNode(struct ListNode* head);

struct ListNode{
	int data;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next )
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
	}
	return slow;
}

void add_before_list(struct ListNode** phead,int val) {
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->next = NULL;
	new_node->data = val;
	if (!(*phead)) {
		*phead = new_node;
		return;
	}
	new_node->next = *phead;
	*phead = new_node;
}
int main(void) {
	struct ListNode* head = NULL;
	add_before_list(&head, 1);
	add_before_list(&head, 2);
	add_before_list(&head, 3);
	add_before_list(&head, 4);
	struct ListNode* middle_node = middleNode(head);
	return 0;
}