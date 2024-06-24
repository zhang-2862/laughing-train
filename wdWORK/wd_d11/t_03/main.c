#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//反转单链表(206. 反转链表)
//
//给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。
//
//struct ListNode* reverseList(struct ListNode* head);

struct ListNode {
	int data;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
	if (!head || !(head->next)) {
		return head;
	}
	struct ListNode* cur = head;
	struct ListNode* pre = NULL;
	struct ListNode* next = NULL;
	while (cur) {
		next = cur->next;
		cur->next = pre;

		//cur，pre，向前移动一个单位
		pre = cur;
		cur = next;
	}
	return pre;
}

void add_before_list(struct ListNode** phead, int val) {
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
	struct ListNode* p=reverseList(head);
	return 0;
}