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
   vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        // 空树直接返回
        if (root == nullptr) {
            return res;
        }
        // 将根节点入队
        aux_que_.push(root);
        // 如果队列不为空
        while (!aux_que_.empty()) {
            int size = aux_que_.size();
            int max_size = size;
            int max_val = 0;
            // 根据每层节点数进行内层循环
            while (size--) {
                // 头结点出队
                TreeNode* node = aux_que_.front();
                aux_que_.pop();
                // 将当前层的元素进行累加
                if (size + 1 == max_size) { // 遍历每层的第一个结点
                    max_val = node->val;
                }
                if (node->val > max_val) { // 大于max_val则更新最大值
                    max_val = node->val;
                }
                // 若该结点的左右孩子不为空，则入队
                if (node->left != nullptr) {
                    aux_que_.push(node->left);
                }
                if (node->right != nullptr) {
                    aux_que_.push(node->right);
                }
            }
            res.push_back(max_val);
        }
        return res;
    }

private:
    queue<TreeNode*> aux_que_;
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
