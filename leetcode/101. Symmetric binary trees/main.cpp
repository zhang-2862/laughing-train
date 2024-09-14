#include <iostream>
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return sym(root, root);
    }
    // 判断两棵树是否对称，只需判断其左子树是否与右子树相对称
    bool sym(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right != nullptr) {
            return false;
        } else if (left->val != right->val) {
            return false;
        }
        bool l_sym = sym(left->left, right->right);
        bool r_sym = sym(left->right, right->left);
        return l_sym && r_sym;
    }
};

// 按层序遍历根节点的左右子树中的对称位置结点
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* l_cur = q.front();
            q.pop();
            TreeNode* r_cur = q.front();
            q.pop();
            if (!l_cur&& !r_cur) {
                continue;
            }
            if (!l_cur || !r_cur || l_cur->val != r_cur->val) {
                return false;
            }
            q.push(l_cur->left);
            q.push(r_cur->right);
            q.push(l_cur->right);
            q.push(r_cur->left);
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
