// 701 二叉搜索树中的插入操作 2024-09-22 11:29:05

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
    // 思路为递归查找查询失败结点找到失败结点立刻返回nullptr,结束递归
    TreeNode *pre = nullptr;
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        Inorder(root, val);
        if (pre->val > val) {
            pre->left = new TreeNode(val);
        } else {
            pre->right = new TreeNode(val);
        }
        return root;
    }

    TreeNode* Inorder(TreeNode* cur, int val) {
        if (cur == nullptr) {
            return cur;
        }
        pre = cur;
        if (cur->val >= val) {
            if (!Inorder(cur->left, val)) {
                return nullptr;
            }
        }
        if (!Inorder(cur->right, val)) {
            return nullptr;
        }
        return nullptr;
    }
};

// 简化版
class Solution2 {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// 迭代法
class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur) {
            if (cur->val > val) {
                prev = cur;
                cur = cur->left;
            } else {
                prev = cur;
                cur = cur->right;
            }
        }
        if (prev->val >= val) {
            prev->left = new TreeNode(val);
        } else {
            prev->right = new TreeNode(val);
        }
        return root;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
