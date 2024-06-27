#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//给定一个二叉树 root ，返回其最大深度。
//
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//	int maxDepth(struct TreeNode* root) {
//
//}

typedef int K;

typedef struct tree_node {
	K key;
	struct tree_node* left;
	struct tree_node* right;
} TreeNode;

typedef struct {
	TreeNode* root;
} BST;
BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}

void bst_insert(BST* tree, K key) {
	// 1. 找到添加的位置
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;

	int cmp;
	while (curr) {
		cmp = key - curr->key;
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
	newnode->key = key;
	// b. 链接
	if (parent == NULL) {
		tree->root = newnode;
	} else if (cmp < 0) {
		parent->left = newnode;
	} else {
		parent->right = newnode;
	}
}


int maxDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}
	int left_depth=maxDepth(root->left);
	int right_depth=maxDepth(root->right);
	return left_depth > right_depth ? left_depth+1 : right_depth+1;
}


int main(void) {
	BST* bst = bst_create();
	bst_insert(bst, 1);
	bst_insert(bst, 4);
	bst_insert(bst, 7);
	bst_insert(bst, 9);
	bst_insert(bst, 3);
	bst_insert(bst, 5);

	int depth = maxDepth(bst->root);
	printf("depth is %d.\n", depth);

	int depth_2 = maxDepth_2(bst->root, 0);
	printf("depth_2 is %d.\n", depth_2);

	//int depth_3 = BT_depth1(bst->root, 0);
	//printf("depth_2 is %d.\n", depth_3);

	return 0;
}