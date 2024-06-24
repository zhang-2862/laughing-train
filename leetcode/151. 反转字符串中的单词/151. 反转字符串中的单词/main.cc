// Created on ...24/6/20
#include <iostream>
#include <string>

using namespace std;

//Not fully understood
void removeExtraSpaces_2(string& s) {
    int slow_index = 0, fast_index = 0;
    for (; fast_index < s.size(); fast_index++)
    {
        if (s[fast_index] != ' ') {
            if (slow_index > 0) {
                s[slow_index++] = ' ';
            }
            while (fast_index < s.size() && s[fast_index] != ' ')
            {
                s[slow_index++] = s[fast_index++];
            }
        }
    }
    s.resize(slow_index);
}

void removeExtraSpaces(string& s) {
  int slowIndex = 0, fastIndex = 0;  // 定义快指针，慢指针
  // 去掉字符串前面的空格
  while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
    fastIndex++;
  }
  for (; fastIndex < s.size(); fastIndex++) {
    // 去掉字符串中间部分的冗余空格
    if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] &&
        s[fastIndex] == ' ') {
      continue;
    } else {
      s[slowIndex++] = s[fastIndex];
    }
  }
  if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {  // 去掉字符串末尾的空格
    s.resize(slowIndex - 1);
  } else {
    s.resize(slowIndex);  // 重新设置字符串大小
  }
}



void reverse_s(string& s,int left,int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverseString(string& s) {
    reverse_s(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == ' ' || i==s.size()) {
            reverse_s(s, start, i - 1);
            start = i + 1;
        }
    }
}

int main() {
  string s;
  getline(cin, s);
  removeExtraSpaces_2(s);
  reverseString(s);
  cout << s << endl;

  return 0;
}
