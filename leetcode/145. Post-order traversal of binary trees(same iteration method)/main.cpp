#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = nullptr;
        // 通用循环迭代法，用后置空指针标记应该处理的结果，将遍历结果逆序压栈，弹栈时放入结果集
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur != nullptr) {
                s.push(cur);
                s.push(nullptr);
                if (cur->right != nullptr) {
                    s.push(cur->right);
                }
                if (cur->left != nullptr) {
                    s.push(cur->left);
                }
            } else {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
            }
        }
        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
