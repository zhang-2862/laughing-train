#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (st_.empty() || st_.top() != s[i]) {
                // 栈为空或不等于栈顶元素则直接入栈
                st_.push(s[i]);
            } else {
                st_.pop();
            }
        }
//        string res = "";
        string res;
        while (!st_.empty()) {
           res += st_.top();
           st_.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    stack<char> st_;
};

int main() {
    Solution obj;
    string res = obj.removeDuplicates("abbaca");
    cout << res;
    return 0;
}
