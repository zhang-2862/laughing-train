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

// 层序遍历法
class Solution {
public:
    // 思路：反转一颗树只需要交换其左右子树即可 故采用递归
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
