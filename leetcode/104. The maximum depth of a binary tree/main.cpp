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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
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
            }
            // 每当遍历完一层结点后 最大深度加1
            maxDepth++;
        }
        return maxDepth;
    }

private:
    queue<TreeNode*> queue_;
};

// 深度优先，递归法
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightdepth= maxDepth(root->right);
        return 1 + max(leftDepth, rightdepth);
    }

};

// 前序遍历法
class Solution3 {
public:
    Solution3()
        : max_depth_(0)
    {}
    void maxDepth(TreeNode* root, int max_depth) {
        if (!root) {
            return;
        }
        // 设置全局变量更新树的高度
        if (max_depth > max_depth_) {
            max_depth_ = max_depth;
        }
        maxDepth(root->left, max_depth + 1);
        maxDepth(root->right, max_depth + 1);
    }
private:
    int max_depth_;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}