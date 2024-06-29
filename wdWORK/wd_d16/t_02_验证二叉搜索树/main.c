#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
//https://leetcode.cn/problems/validate-binary-search-tree/description/

//Leetcode 98. 验证二叉搜索树
//
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//
//有效 二叉搜索树定义如下：
//
//节点的左子树只包含 小于 当前节点的数。
//节点的右子树只包含 大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。

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
	// 1. 找到添加的位置
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
			// key 已存在
			return;
		}
	}	// curr == NULL, cmp = key - parent->key
	// 2. 添加节点
	// a. 创建节点并初始化
	TreeNode* newnode = calloc(1, sizeof(TreeNode));
	newnode->val = key;
	// b. 链接
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
	struct TreeNode* pre = NULL;//记录前一个访问的结点
	if (root == NULL) {
		return true;
	}
	bool left=isValidBST(root->left);
	
	//判断当前根结点与左右孩子大小关系
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
	//}//错误做法，不能确保每一颗子树都有二叉搜索树的性质

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
//无法正确判断单个结点的二叉树
bool isBST(TreeNode* root) {
	//无效 static struct TreeNode* pre = NULL;//记录前一个访问的结点
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

//需重新在一个函数内将指针赋值作为局部变量使用
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