#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//合并两条有序链表(21. 合并两个有序链表）
//将两个升序链表合并为一个新的升序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。(要求: 不能额外申请堆内存空间)。

struct ListNode {
	int data;
	struct ListNode* next;
};

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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1) {
		return list2;
	}
	if (!list2) {
		return list1;
	}
	struct ListNode* new_head = NULL;
	struct ListNode* new_tail = NULL;
	while (list1 && list2)
	{
		if (list1->data < list2->data) {
			if (!new_head) {
				new_head = list1;
				new_tail = list1;
			} else {
				new_tail->next = list1;
				new_tail = new_tail->next;
			}
			list1 = list1->next;
		} else {
			if (!new_head) {
				new_head = list2;
				new_tail = list2;
			} else {
				new_tail->next = list2;
				new_tail = new_tail->next;
			}
			list2 = list2->next;
		}
	}
	if (!list1) {
		new_tail->next = list2;
		return new_head;
	}
	if (!list2) {
		new_tail->next = list1;
		return new_head;
	}
}


//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	//递归条件
//	if (l1 == NULL) return l2;
//	if (l2 == NULL) return l1;
//
//	if (l1->data < l2->data) {
//		l1->next = mergeTwoLists(l1->next, l2);
//
//		return l1;
//	} else {
//		l2->next = mergeTwoLists(l1, l2->next);
//
//		return l2;
//	}
//}

int main(void) {
	struct ListNode* head = NULL;
	add_before_list(&head, 7);
	add_before_list(&head, 5);
	add_before_list(&head, 3);
	add_before_list(&head, 1);

	struct ListNode* head_b = NULL;
	add_before_list(&head_b, 8);
	add_before_list(&head_b, 6);
	add_before_list(&head_b, 4);
	add_before_list(&head_b, 2);

	head=mergeTwoLists(head, head_b);

	return 0;
}