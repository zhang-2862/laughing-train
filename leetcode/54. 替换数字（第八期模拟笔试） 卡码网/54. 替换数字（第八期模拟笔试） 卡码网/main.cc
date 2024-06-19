//Created on ...24/6/19
#include <iostream>

//54. 替换数字（第八期模拟笔试）
//时间限制：1.000S  空间限制：128MB
//题目描述
//给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
//输入描述
//输入一个字符串 s, s 仅包含小写字母和数字字符。
//输出描述
//打印一个新的字符串，其中每个数字字符都被替换为了number
//输入示例
//
//a1b2c3
//
//输出示例
//
//anumberbnumbercnumber
//
//提示信息
//数据范围：
//1 <= s.length < 10000。

using namespace std;

void replacementDigit(string& s) {
    int num_count = 0;
    auto begin = s.begin();
    while (begin != s.end()) {
        if (isdigit(*begin++)) {
            num_count++;
        }
    }
    int old_index = s.size() - 1;
    s.resize(s.size() + num_count * 5);
    int new_index = s.size() - 1;
    while (old_index >= 0) {
        if (isdigit(s[old_index])) {
            s[new_index--] = 'r';
            s[new_index--] = 'e';
            s[new_index--] = 'b';
            s[new_index--] = 'm';
            s[new_index--] = 'u';
            s[new_index--] = 'n';
        }
        else {
            s[new_index--] = s[old_index];
        }
        old_index--;
    }
}
int main() {
    string str;
    cin >> str;
    replacementDigit(str);
    cout << str << endl;

    return 0;
}