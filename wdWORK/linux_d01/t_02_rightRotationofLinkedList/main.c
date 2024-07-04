#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//给定一个链表，将链表向右旋转 k 位
//
//Node* rotateRight(Node* head, int k);
//
//输入: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 0
//输出：2-- > 3 -- > 5 -- > 4 -- > 9 -- > 6
//
//
//输入: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 2
//输出：9-- > 6 -- > 2 -- > 3 -- > 5 -- > 4
//
//
//输入: 2 -- > 3 -- > 5 -- > 4 -- > 9 -- > 6, k = 9
//输出：4-- > 9 -- > 6 -- > 2 -- > 3 -- > 5

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
	Node* old_head = head;//保存旧头节点
	
		//找原链表尾结点
	int list_size = 0;
	Node* old_tail = NULL;
	while (head) {
		old_tail = head;
		head = head->next;
		list_size++;
	}

	k %= list_size;
	// 寻找倒数第N个结点
	// fast指针先走k步
	while (k--) {
		fast = fast->next;
	}// 因为是右旋 fast不可能指向NULL，故不考虑fast指向NULL的情况

	Node* new_tail = NULL;
	while (fast) {
		new_tail = slow;
		slow = slow->next;
		fast = fast->next;
	}// 循环结束时，slow指向的结点为新的head结点

	//两部分链表完成链接
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
