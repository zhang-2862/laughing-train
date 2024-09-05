#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (const auto &item: tokens) {
            if (item.size() == 1 && isOperator(item[0])) {
                int rhs = st_.top();
                st_.pop();
                int lhs = st_.top();
                st_.pop();
                int res = calculate(lhs, rhs, item[0]);
                st_.push(res);
            } else {
                st_.push(stoi(item));
            }
        }
        return st_.top();
    }

    // 优化，也可以直接传字符串进行比较
    bool isOperator (char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return true;
        }
        return false;
    }

    int calculate(int x, int y, char c) {
        if (c == '+') {
            return x + y;
        } else if (c == '-') {
            return x - y;
        } else if (c == '*') {
            return x * y;
        } else {
            return x / y;
        }
    }
private:
    stack<int> st_;
};

int main() {
    //vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol;
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}
