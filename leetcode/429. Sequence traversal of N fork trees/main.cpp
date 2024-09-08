#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
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
            vector<int> level;
            // 根据每层节点数进行内层循环
            while (size--) {
                // 头结点出队
                Node* node = aux_que_.front();
                aux_que_.pop();
                level.push_back(node->val);
                // 若该结点的孩子不为空，则按次序入队
                if (!node->children.empty()) {
                    for (int i = 0; i < node->children.size(); i++) {
                        aux_que_.push(node->children[i]);
                    }
                }
            }
            res.push_back(level);
        }
        return res;
    }

private:
    queue<Node*> aux_que_;
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
