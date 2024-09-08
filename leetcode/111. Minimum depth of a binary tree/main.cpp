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
    int minDepth(TreeNode* root) {
        int minDepth = 0;
        if (!root) {
            return 0;
        }

        queue_.push(root);
        while (!queue_.empty()) {
            int size = queue_.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue_.front();
                queue_.pop();
                if (node->left) {
                    queue_.push(node->left);
                }
                if (node->right) {
                    queue_.push(node->right);
                }
                // 若当前层存在叶子结点，则直接返回当前深度 + 1
                if (!node->left && !node->right) {
                    return minDepth + 1;
                }
            }
            // 每遍历完一层结点后 最大深度加1
            minDepth++;
        }
        return minDepth;
    }

private:
    queue<TreeNode*> queue_;
};

// 深度优先，递归法
// 要知道一颗树的最小高度，只需计算左右子树最小高度+1，递归求解即可
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftDepth = minDepth(root->left);
        int rightdepth= minDepth(root->right);
        return 1 + min(leftDepth, rightdepth);
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
