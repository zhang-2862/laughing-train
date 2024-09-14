// 559 N 叉树的最大深度 2024-09-11 09:11:08

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// Definition for a Node.
/*
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
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int max_depth = 0;
        for (Node* child : root->children) {
            /*if (max_depth < maxDepth(child)) {
                max_depth = maxDepth(child);
            }*/ // 错误原因在于两次调用maxDepth造成无限递归，最终超时
            max_depth = max(max_depth, maxDepth(child));
        }
        return max_depth + 1;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main(void) {
    cout << "hello-world" << endl;
}
