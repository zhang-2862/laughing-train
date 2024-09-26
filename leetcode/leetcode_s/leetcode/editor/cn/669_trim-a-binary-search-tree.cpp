// 669 修剪二叉搜索树 2024-09-22 19:49:21

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

#if 0
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution1 {
public:
    // 先序遍历
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 终止条件
        if (root == nullptr) {
            return root;
        }
        // 处理当前层
        if (root->val < low) {// 当前结点小于左边界,返回修剪后的右子树
            return trimBST(root->right, low, high);
        }
        if (root->val > high) { // 当前结点大于右边界,返回修剪后的左子树
            return trimBST(root->left, low, high);
        }
        // 左
        root->left = trimBST(root->left, low, high);
        // 右
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return root;
        }
        // 将根节点移动到对应的修剪区间内
        while (root && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            } else if (root->val > high) {
                root = root->left;
            }
        }
        TreeNode* cur = root;// 用于遍历处理结点
        // 处理左子树
        while (cur) {
            while (cur->left && (cur->left->val < low)) {
                cur->left = cur->left->right;
            } //循环结束 说明当前结点的左孩子为空，或者左孩子的值在左边界的右边,即不用被剪掉
            cur = cur->left; // 此时左孩子是符合条件的结点,cur向左移动(右边必定是符合条件的结点),进入下一轮while
        }
        cur = root; // 重置cur
        // 处理右子树
        while (cur) {
            while (cur->right && (cur->right->val > high)) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
