// 530 二叉搜索树的最小绝对差 2024-09-21 16:36:45

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

// 因为时二叉搜索树，采用中序遍历，访问顺序是有序的，只需考虑后一个结点减去前一个结点的差值,进行比较更新
class Solution1 {
public:
    int result = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
    void traversal(TreeNode* cur) {
        if (!cur) {
            return;
        }
        traversal(cur->left);
        if (pre != nullptr) {
            result = min(result, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }
};

// 迭代法，中序遍历
class Solution {
public:
    int result = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left; // 直到左孩子为空
            } else {
                cur = st.top(); // 中
                st.pop();
                if (pre != nullptr) {
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;// 右
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
