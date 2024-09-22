// 235 二叉搜索树的最近公共祖先 2024-09-22 09:34:42

#include<bits/stdc++.h>
#include <utility>

using namespace std;
using std::swap;

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


class Solution1 {
public:
    int left_bound = 0;
    int right_bound = 0;
    TreeNode* res = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        left_bound = p->val;
        right_bound = q->val;
        if (left_bound > right_bound) {
            swap(left_bound, right_bound);
        }
        preOrder(root);
        return res;
    }

    bool isInRange(int x) {
        return left_bound <= x && x <= right_bound;
    }

    // 遍历二叉树找到结果集区间
    void preOrder(TreeNode* root) {
        if (!root) {
            return;
        }
        cout << root->val << ' ';
        if (isInRange(root->val)) {
            res = root;
            return;
        }
        preOrder(root->left);
        preOrder(root->right);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        if (p->val < root->val && q->val < root->val) {
            // 说明结果在左子树中
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            // 说明结果在右子树中
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
