// 538 把二叉搜索树转换为累加树 2024-09-24 10:49:23

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
    // 思路：右中左的遍历顺序，利用pre指针记录前一个结点的值，依次遍历所有结点，
    // 更新每个结点的值（变为当前值加上前一个结点的值之和）
    TreeNode* pre = nullptr;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        if (pre != nullptr) {
            root->val += pre->val;
        }
        pre = root;
        convertBST(root->left);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
