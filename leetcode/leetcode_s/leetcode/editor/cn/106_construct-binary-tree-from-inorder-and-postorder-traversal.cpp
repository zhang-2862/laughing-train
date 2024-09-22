// 106 从中序与后序遍历序列构造二叉树 2024-09-19 12:43:52

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

// Definition for a binary tree node.
#if 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        // 根节点为后序遍历中的最后一个元素
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        if (postorder.size() == 1) {
            return root;
        }
        // 将根节点从postorder中移除
        postorder.resize(postorder.size() - 1);
        // 以根节点为分界点，将中序遍历数组一分为二
        int inorder_idx;
        for (inorder_idx = 0; inorder_idx < inorder.size(); inorder_idx++) {
            if (inorder[inorder_idx] == root->val) {
                break;
            }
        }
        // 确定中序遍历的左右数组，然后根据中序遍历左右数字的size，确定后续遍历的左右数组
        // 左闭右开
        vector<int> left_inorder(inorder.begin(), inorder.begin() + inorder_idx);
        vector<int> right_inorder(inorder.begin() + inorder_idx + 1, inorder.end());

        vector<int> left_postorder(postorder.begin(),
            postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(),
            postorder.end());

        // 递归
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
