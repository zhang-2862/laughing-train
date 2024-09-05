#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preoder(root, v);
        return v;
    }

    void preoder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        v.push_back(root->val);
        preoder(root->left,v);
        preoder(root->right,v);
    }
};

// 迭代法
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }

    void preorder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                v.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);
            }
        }
    }
private:
    stack<TreeNode*> st;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
