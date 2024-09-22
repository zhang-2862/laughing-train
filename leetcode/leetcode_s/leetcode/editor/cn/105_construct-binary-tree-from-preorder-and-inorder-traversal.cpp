// 105 从前序与中序遍历序列构造二叉树 2024-09-19 12:44:00

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

// 与106类似，不创建新的vector，采用下标法优化内存
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 题目给出vector最小为1，且preoder的长度与inorder相等 故不判断特殊情况
        // 采用左闭右开区间
        return Traversal(preorder, 0, preorder.size(),
                        inorder, 0, inorder.size());
    }

    TreeNode* Traversal(vector<int>& preorder, int first_preorder_idx, int last_preorder_idx,
                        vector<int>& inorder, int first_inorder_idx, int last_inorder_idx) {
        if (first_preorder_idx == last_preorder_idx) {
            // 大小为0，返回空节点
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[first_preorder_idx]);
        if (last_preorder_idx - 1 == first_preorder_idx) {
            return root;
        }
        // 找到左右子树的分界点
        int idx = 0;
        for (idx = first_inorder_idx; idx < last_inorder_idx; idx++) {
            if (root->val == inorder[idx]) {
                break;
            }
        }
        // 切割中序数组
        int left_first_inorder_idx = first_inorder_idx;
        int left_last_inorder_idx = idx;;
        int right_first_inorder_idx = idx + 1;
        int right_last_inorder_idx = last_inorder_idx;
        // 切割前序数组
        int left_first_preorder_idx = first_preorder_idx + 1;// 第一个元素已经作为根结点了
        int left_last_preorder_idx = left_first_preorder_idx + idx - first_inorder_idx;;
        int right_first_preorder_idx = left_last_preorder_idx;
        int right_last_preorder_idx = last_preorder_idx;

        // 递归
        root->left = Traversal(preorder, left_first_preorder_idx, left_last_preorder_idx,
                               inorder, left_first_inorder_idx, left_last_inorder_idx);
        root->right = Traversal(preorder, right_first_preorder_idx, right_last_preorder_idx,
                               inorder, right_first_inorder_idx, right_last_inorder_idx);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
