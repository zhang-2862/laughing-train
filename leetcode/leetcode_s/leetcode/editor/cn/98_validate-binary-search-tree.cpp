// 98 验证二叉搜索树 2024-09-21 20:10:50

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

// 时隔三个月再见此题
// 思路 递归验证左右子树是否为二叉搜索树,(二叉搜索树首先考虑中序遍历)
class Solution {
public:
    TreeNode* pre = nullptr;//利用pre指针 比较前后结点是否逆序
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
            // 空节点默认为二叉搜索树
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (pre != nullptr) {
            if (pre->val >= root->val) {
                return false;
            }
        }
        pre = root;
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
