// 513 找树左下角的值 2024-09-17 15:38:08

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
    int max_depth = -1;
    int res = 0;
    int findBottomLeftValue(TreeNode* root) {
        helper(root, 0);
        return res;
    }

    // 首先审题得知是最底层的最左，无关左右孩子结点。(这样一来就简单了）
    void helper(TreeNode* root, int depth) {
        if (depth > max_depth) {// 因为只在第一次遍历该层的结点时才更新值，
                                // 按照根左右的顺序遍历，故此值一定为最左结点。
            max_depth = depth;
            res = root->val;
        }
        if (root->left) {
            helper(root->left, depth + 1);
        }
        if (root->right) {
            helper(root->right, depth + 1);
        }
    }
};

// 复习一下层次遍历,这题用层次遍历也比较简单
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
                if (i == 0) {//该层第一个结点
                    res = node->val;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
