// 113 路径总和 II 2024-09-17 17:52:05

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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return res;
        }
        vector<int> path;
        preOrder(root, targetSum, path);
        return res;
    }

    // count用来计数，路径上每加入一个结点，count减去相应的val，当遍历到叶子结点时
    // 判断其是否等于count。
    void preOrder(TreeNode* root, int count, vector<int>& path) {
        if (!root->left && !root->right) {
            if (root->val == count) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        if (root->left) {
            path.push_back(root->val);
            preOrder(root->left, count - root->val, path);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->val);
            preOrder(root->right, count - root->val, path);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
