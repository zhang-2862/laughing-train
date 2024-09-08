#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        aux_que_.push(root);

        while (!aux_que_.empty()) {
            Node* cur = nullptr;
            Node* prev = nullptr;
            int size = aux_que_.size();
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    cur = aux_que_.front();
                    aux_que_.pop();
                    prev = cur;
                } else {
                    cur = aux_que_.front();
                    aux_que_.pop();
                    prev->next = cur;
                    prev = cur;
                }
                if (cur->left != nullptr) {
                    aux_que_.push(cur->left);
                }
                if (cur->right != nullptr) {
                    aux_que_.push(cur->right);
                }
            }
        }

        return root;
    }
private:
    queue<Node*>aux_que_;
};


int main(int argc, char* argv[]) {

    return 0;
}


