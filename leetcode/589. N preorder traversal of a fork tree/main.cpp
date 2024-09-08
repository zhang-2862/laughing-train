#include <iostream>
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder_t(root, res);
        return res;
    }

    void preorder_t(Node* root, vector<int>& res) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        for (auto child : root->children) {
            preorder_t(child, res);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
