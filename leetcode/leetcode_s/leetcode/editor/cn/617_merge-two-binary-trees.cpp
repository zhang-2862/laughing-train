// 617 合并二叉树 2024-09-20 14:13:37

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {// root1 为空则直接返回root2
            return root2;
        }
        if (!root2) { // root2 为空则直接返回root1
            return root1;
        }
        // 以上若两者同为空则随便返回谁都行，故不做特殊处理
        // 两者都不空的逻辑，选择root1为主，将root2的值直接加到root1上
        root1->val += root2->val; //

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* cur1 = que.front();// root1上的结点
            que.pop();
            TreeNode* cur2 = que.front();// root2上的结点
            que.pop();

            cur1->val += cur2->val;

            if (cur1->left && cur2->left) {
                que.push(cur1->left);
                que.push(cur2->left);
            }
            if (cur1->right && cur2->right) {
                que.push(cur1->right);
                que.push(cur2->right);
            }
            // 上述判断条件必须在前面，不然下面if语块会改变原本root1树的结点
            if (!cur1->left && cur2->left) {
                cur1->left = cur2->left;
            }
            if (!cur1->right && cur2->right) {
                cur1->right = cur2->right;
            }
        }
        return root1;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
