// 257 二叉树的所有路径 2024-09-13 22:52:00

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
 // Definition for a binary tree node.
#if 0
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#endif

class Solution_0 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        helper(root, path, res);
        return res;
    }

    void helper(TreeNode* node, vector<int>& path, vector <string>& res) {
        path.push_back(node->val);// 将结点加入路径中
        // 遇到叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            string spath;
            for (int i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]) + "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }
        if (node->left != nullptr) {
            helper(node->left, path, res);
            path.pop_back(); // 回溯
        }
        if (node->right != nullptr) {
            helper(node->right, path, res);
            path.pop_back(); // 回溯
        }
    }
};

class Solution_1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        if (!root) {
            return res;
        }
        helper(root, path, res);
        return res;
    }

    void helper(TreeNode* node, string path, vector<string>& res) {
        path += to_string(node->val);
        if (!node->left && !node->right) { // 访问到叶子结点了
            res.push_back(path);
        }

        if (node->left) {
            helper(node->left, path + "->", res);
        }
        if (node->right) {
            helper(node->right, path + "->", res);
        }
    }
};

// 迭代法
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<TreeNode*> nodes;
        stack<string> paths; //存储遍历的路径
        if (root == nullptr) {
            return res;
        }
        nodes.push(root);
        paths.push(to_string(root->val));

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            string path = paths.top();
            paths.pop();

            // cout << endl;
            // cout << node->val << endl;
            // cout << path << endl;

            if (!node->left && !node->right) {
                res.push_back(path);
            }

            if (node->right) {
                nodes.push(node->right);
                paths.push(path + "->" +to_string(node->right->val));
            }

            if (node->left) {
                nodes.push(node->left);
                paths.push(path + "->" +to_string(node->left->val));
                // 每次访问孩子结点均压入一条路径以便递归回溯
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void insert(TreeNode*& node, int val) {
    if (node == nullptr) {
        node = new TreeNode(val);
        return;
    }
    if (node->val < val) {
        insert(node->left, val);
    } else {
        insert(node->right, val);
    }
}

int main() {
    TreeNode * root = new TreeNode(6);

    insert(root, 4);
    insert(root, 7);
    insert(root, 8);
    insert(root, 3);
    insert(root, 5);

    Solution0 test;
    test.binaryTreePaths(root);
}
