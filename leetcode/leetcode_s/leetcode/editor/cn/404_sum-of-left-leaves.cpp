// 404 左叶子之和 2024-09-17 15:10:56

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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int left_val = 0;
        if (root->left) {
            left = sumOfLeftLeaves(root->left);
            if (!root->left->left && !root->left->right) {
                // 左叶子结点
                left_val = root->left->val;
            }
        }
        if (root->right) {
            right = sumOfLeftLeaves(root->right);
        }
        return left + right + left_val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
