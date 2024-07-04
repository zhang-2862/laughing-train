#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����һ������������������ת k λ
//
//Node* rotateRight(Node* head, int k);
//
//����: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 0
//�����2-- > 3 -- > 5 -- > 4 -- > 9 -- > 6
//
//
//����: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 2
//�����9-- > 6 -- > 2 -- > 3 -- > 5 -- > 4
//
//
//����: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 9
//�����4-- > 9 -- > 6 -- > 2 -- > 3 -- > 5

typedef struct Node {
	int val;
	struct Node* next;
}Node;

Node* rotateRight(Node* head, int k) {
	if (k == 0) {
		return head;
	}
	Node* slow = head;
	Node* fast = head;
	Node* old_head = head;//�����ͷ�ڵ�
	
		//��ԭ����β���
	int list_size = 0;
	Node* old_tail = NULL;
	while (head) {
		old_tail = head;
		head = head->next;
		list_size++;
	}

	k %= list_size;
	// Ѱ�ҵ�����N�����
	// fastָ������k��
	while (k--) {
		fast = fast->next;
	}// ��Ϊ������ fast������ָ��NULL���ʲ�����fastָ��NULL�����

	Node* new_tail = NULL;
	while (fast) {
		new_tail = slow;
		slow = slow->next;
		fast = fast->next;
	}// ѭ������ʱ��slowָ��Ľ��Ϊ�µ�head���

	//�����������������
	old_tail->next = old_head;
	new_tail->next = NULL;

	return slow;
}

void insert_befor_head(Node** phead, int val) {
	Node* new_node = malloc(sizeof(Node));
	new_node->val = val;
	new_node->next = NULL;
	if (*phead == NULL) {
		*phead = new_node;
		return;
	}
	new_node->next = (*phead);
	*phead = new_node;
}

int main(void) {
	Node* head = NULL;
	insert_befor_head(&head, 6);
	insert_befor_head(&head, 9);
	insert_befor_head(&head, 4);
	insert_befor_head(&head, 5);
	insert_befor_head(&head, 3);
	insert_befor_head(&head, 2);

	int k;
	scanf("%d", &k);
	Node* newhead=rotateRight(head, k);

	while (newhead) {
		printf("%d -> ",newhead->val);
		newhead = newhead->next;
	}

	return 0;
}
