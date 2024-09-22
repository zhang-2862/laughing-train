// 450 删除二叉搜索树中的节点 2024-09-22 15:14:02

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            if (root->left != nullptr && root->right == nullptr) {
                return root->left;
            }
            if (root->right != nullptr && root->left == nullptr) {
                return root->right;
            }
            if (root->right != nullptr && root->left != nullptr) {
                TreeNode* cur = root->right;
                TreeNode* parent = root->right;
                while (cur) { // 寻找右子树中最左端结点
                    parent = cur;
                    cur = cur->left;
                }
                TreeNode* tmp = root;
                parent->left = root->left; // 将待删除结点的左子树接到右子树最左端下方
                root = root->right;
                delete tmp;
                return root;
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
