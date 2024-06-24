#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//�жϵ������Ƿ��л� ? (141. ��������)
//
//����һ������ĵ�һ���ڵ� head ���ж��������Ƿ��л�
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


//�����ڲ��ԣ�����һ����������
void setCycle(struct ListNode* head) {
	struct ListNode* p = head;
	//�ҵ����һ���ڵ�
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