// 222 完全二叉树的节点个数 2024-09-11 09:12:32

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

class Solution0 {
public:
    int node_num = 0;
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // 一棵树的结点总数 = 左子树结点加右子树结点 + 本身
        int left_nums = 0;
        int right_nums = 0;
        // if (set_.count(root->left) == 0) {
            // set_.insert(root->left);
            left_nums = countNodes(root -> left);
        // }
        // if (set_.count(root->right) == 0) {
            // set_.insert(root->right);
            right_nums = countNodes(root -> right);
        // }
        return left_nums + right_nums + 1;
    }
// private:
    // unordered_set<TreeNode*> set_;//用来记录结点是否访问过
};

// 优化方案：找完全二叉树,直接用公式计算 完全二叉树结点个数等于2^h - 1
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == 0) {
            return 0;
        }
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        int left_depth = 0;
        int right_depth = 0;
        while (left) {
            left = left -> left;
            left_depth++;
        }
        while (right) {
            right = right -> right;
            right_depth++;
        }
        if (left_depth == right_depth) {
            return (2 << left_depth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(void) {
    cout << "Hello, World!" << endl;
}