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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // 空树直接返回
        if (root == nullptr) {
            return res;
        }
        // 将根节点入队
        aux_que_.push(root);
        // 如果队列不为空
        while (!aux_que_.empty()) {
            int size = aux_que_.size();
            vector<int> tmp;
            // 根据每层节点数进行内层循环
            while (size--) {
                // 头结点出队
                TreeNode* node = aux_que_.front();
                aux_que_.pop();
                // 将出队元素放入结果集
                tmp.push_back(node->val);
                // 若该结点的左右孩子不为空，则入队
                if (node->left != nullptr) {
                    aux_que_.push(node->left);
                }
                if (node->right != nullptr) {
                    aux_que_.push(node->right);
                }
            }
            // 将本层vector放入结果集中
            res.push_back(tmp);
        }
        return res;
    }

private:
    queue<TreeNode*> aux_que_;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
