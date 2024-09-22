// 700 二叉搜索树中的搜索 2024-09-21 15:09:44

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        if (root->val > val) {// 当前结点值大于val, 递归去其左子树中寻找
            return searchBST(root->left, val);
        }
        // if (root->val < val) {// 当前结点值小于val, 递归去其右子树中寻找
        //     return searchBST(root->right, val);
        // }
        return searchBST(root->right, val);
        // 等于当前结点值，直接返回
        // return root;
    }
};

class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val < val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
