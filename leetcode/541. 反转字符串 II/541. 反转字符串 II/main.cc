//Created on ...24/6/19
#include <iostream>
//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

using namespace std;
string reverseStr(string s, int k) {
    int count = 0;
    for (int i = 0; i < s.size(); i += 2 * k) {
        int left = i;
        int right;
        if (i + k - 1 < s.size()) {
            right = i + k - 1;
        }
        else {
            right = s.size() - 1;
        }
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    s=reverseStr(s, k);

    cout << s;

    return 0;
}