// 112 路径总和 2024-09-17 17:09:18

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
    bool flag = false;
    int target_sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        target_sum = targetSum;
        int sum = 0;
        pathSum(root, sum);
        return flag;
    }

    void pathSum(TreeNode* root, int sum) {
        sum += root->val;
        if (!root->left && !root->right) {
            flag = flag || target_sum == sum;// 更新全局变量的值,有一条路径符合条件即为真
            return;
        }
        if (root->left) {
            pathSum(root->left, sum);
        }
        if (root->right) {
            pathSum(root->right, sum);
        }
    }
};

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while (!s.empty()) {
            pair<TreeNode*, int> p = s.top();
            s.pop();
            if (!p.first->left && !p.first->right && p.second == targetSum) {
                return true;
            }
            if (p.first->left) {
                s.push({p.first->left, p.second + p.first->left->val});
            }
            if (p.first->right) {
                s.push({p.first->right, p.second + p.first->right->val});
            }
        }
        return false;
    }
};

class Solution {
public:
    bool hasPathSum1(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return pathSum(root, targetSum - root->val);
    }

    bool pathSum(TreeNode* root, int count) {
        if (!root->left && !root->right) { // 如果是叶子结点
            return count == 0; // 返回计数是否减到0, 计数为0 则说明存在一条路径使得和为target
        }
        if (root->left) {
            if (pathSum(root->left, count - root->left->val)) {
                return true;
            }
        }
        if (root->right) {
            if (pathSum(root->right, count - root->right->val)) {
                return true;
            }
        }
        return false;
    }
    // 精简版
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
            hasPathSum(root->right, targetSum - root->val);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
