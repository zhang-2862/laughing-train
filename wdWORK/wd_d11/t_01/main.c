#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�������м���(876. ������м���)
//
//����������ĵ�һ����� head �������ҳ�������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
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