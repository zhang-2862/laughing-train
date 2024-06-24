#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//判断单链表是否有环 ? (141. 环形链表)
//
//给定一个链表的第一个节点 head ，判断链表中是否有环
//
//bool hasCycle(struct ListNode* head);

struct ListNode {
	int data;
	struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
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


//仅用于测试，设置一个环形链表
void setCycle(struct ListNode* head) {
	struct ListNode* p = head;
	//找到最后一个节点
	while (p->next) {
		p = p->next;
	}
	p->next = head;
}

int main(void) {
	struct ListNode* head = NULL;
	add_before_list(&head, 1);
	add_before_list(&head, 2);
	add_before_list(&head, 3);
	add_before_list(&head, 4);
	setCycle(head);
	if (hasCycle(head)) {
		printf("yes,hasCycle\n");
	}
	return 0;
}