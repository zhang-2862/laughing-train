#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        for (int i = 0; i < s.size(); ++i) {
           if (s[i] == '(') {
               st_.push(')');
           } else if (s[i] == '{') {
               st_.push(('}'));
           } else if (s[i] == '[') {
               st_.push(']');
           } else if (st_.empty() || st_.top() != s[i]) {
               return false;
           } else { // 匹配成功
               st_.pop();
           }
        }
        return st_.empty();
    }
private:
    stack<char> st_;
};

int main() {
    Solution obj;
    string s("(())[]}");
    string s1("(())[]");
    if (obj.isValid(s1)) {
        cout << "true" << endl;
    }

    return 0;
}
