#include <algorithm>
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        aux_que_.push(root);
        while (!aux_que_.empty()) {
            int size = aux_que_.size();
            vector<int> tmp;
            while (size--) {
                TreeNode* node = aux_que_.front();
                aux_que_.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    aux_que_.push(node->left);
                }
                if (node->right != nullptr) {
                    aux_que_.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    queue<TreeNode*> aux_que_;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
