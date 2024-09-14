// 110 平衡二叉树 2024-09-13 12:37:57

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#if 1
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
class Solution0 {
public:
    // 思路为递归判断左右子树高度差是否大于1
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return abs(left_height - right_height) <= 1
        && isBalanced(root->left) && isBalanced(root->right);
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return max(left_height, right_height) + 1;
    }
};

// 优化思路：求高度时，一旦左右子树高度差超过1即返回-1
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_height = getHeight(root->left);
        if (left_height == -1) return -1;

        int right_height = getHeight(root->right);
        if (right_height == -1) return -1;

        return abs(left_height - right_height) > 1
        ? -1 : max(left_height, right_height) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int getDepth(TreeNode* cur) {
    stack<TreeNode*> st;
    if (cur != NULL) st.push(cur);
    int depth = 0; // 记录深度
    int result = 0;
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);                          // 中
            st.push(NULL);
            depth++;
            cout << depth << endl;
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左

        } else {
            st.pop();
            node = st.top();
            st.pop();
            depth--;// 因为是后续遍历，当访问到根结点时，根节点以下的结点均遍历完毕，故深度--，
                    // 回到原来的层级
            cout << depth << endl;
        }
        result = result > depth ? result : depth;
    }
    return result;
}

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    if (root->val > value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

int main(void) {
    TreeNode* root = new TreeNode(1);
    insert(root,3);
    insert(root,2);
    insert(root,5);
    insert(root,4);
    insert(root,6);

    getDepth(root);

}
