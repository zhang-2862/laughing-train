// 236 二叉树的最近公共祖先 2024-09-21 21:03:43

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

#if 0
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        if (left == nullptr && right != nullptr) {
            return right;
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
