#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
//https://leetcode.cn/problems/validate-binary-search-tree/description/

//Leetcode 98. ��֤����������
//
//����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
//
//��Ч �����������������£�
//
//�ڵ��������ֻ���� С�� ��ǰ�ڵ������
//�ڵ��������ֻ���� ���� ��ǰ�ڵ������
//�������������������������Ҳ�Ƕ�����������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //bool isValidBST(struct TreeNode* root) {}

typedef int K;

typedef struct TreeNode {
	K val;
	struct TreeNode* left;
	struct TreeNode* right;	
}TreeNode;

typedef struct {
	TreeNode* root;
} BST;

void bst_insert(BST* tree, K key) {
	// 1. �ҵ���ӵ�λ��
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;

	int cmp;
	while (curr) {
		cmp = key - curr->val;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		} else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		} else {
			// key �Ѵ���
			return;
		}
	}	// curr == NULL, cmp = key - parent->key
	// 2. ��ӽڵ�
	// a. �����ڵ㲢��ʼ��
	TreeNode* newnode = calloc(1, sizeof(TreeNode));
	newnode->val = key;
	// b. ����
	if (parent == NULL) {
		tree->root = newnode;
	} else if (cmp < 0) {
		parent->left = newnode;
	} else {
		parent->right = newnode;
	}

}

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}

bool isValidBST(struct TreeNode* root) {
	struct TreeNode* pre = NULL;//��¼ǰһ�����ʵĽ��
	if (root == NULL) {
		return true;
	}
	bool left=isValidBST(root->left);
	
	//�жϵ�ǰ����������Һ��Ӵ�С��ϵ
	//int left_val = 0;
	//int right_val = 0;
	//int root_val = root->val;
	//if (root->left != NULL) {
	//	left_val = root->left->val;
	//	if (left_val > root_val) {
	//		flag = false;
	//		return false;
	//	}
	//}
	//if (root->right != NULL) {
	//	right_val = root->right->val;
	//	if (right_val < root_val) {
	//		flag = false;
	//		return false;
	//	}
	//}//��������������ȷ��ÿһ���������ж���������������

	if (pre != NULL && root->val <= pre->val) {
		return false;
	}
	pre = root;

	bool right=isValidBST(root->right);
	return (left && right);
}

void insert_binary_tree(TreeNode* root,K val) {
	if (root == NULL) {
		return;
	}
	if (root->left == NULL) {
		root->left = calloc(1,sizeof(TreeNode));
		root->left->val = val;
		return;
	}
	if (root->right == NULL) {
		root->right = calloc(1,sizeof(TreeNode));
		root->right->val = val;
	}
}

struct TreeNode* pre = NULL;
//�޷���ȷ�жϵ������Ķ�����
bool isBST(TreeNode* root) {
	//��Ч static struct TreeNode* pre = NULL;//��¼ǰһ�����ʵĽ��
	if (root == NULL) {
		return true;
	}
	bool left = isBST(root->left);

	if (pre != NULL && root->val >= pre->val) {
		return false;
	}
	pre = root;

	bool right = isBST(root->right);
	return left && right;
}

//��������һ�������ڽ�ָ�븳ֵ��Ϊ�ֲ�����ʹ��
bool is_valid_bst(TreeNode* root) {
	pre = NULL;
	return isBST(root);
}

int main(void) {
	
	//BST* bst=bst_create();

	//if (isValidBST(bst->root)) {
	//	printf("is a binary search tree!\n");
	//} else {
	//	printf("is not a binary search tree!\n");
	//}

	TreeNode* root = calloc(1, sizeof(TreeNode));
	//insert_binary_tree(root, 4);
	//insert_binary_tree(root, 2);
	//insert_binary_tree(root->left, 7);
	//insert_binary_tree(root->right, 5);
	//insert_binary_tree(root->right, 9);

	if (isBST(root)) {
		printf("is a binary search tree!\n");
	} else {
		printf("is not a binary search tree!\n");
	}

	return 0;
}