// Created on ...24/6/20
#include <iostream>
#include <string>

using namespace std;

void reverse_s(string& s, int start, int end) {
  char temp;
  end--;
  while (start < end) {
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }
}

string reverseWords(string s) {
  int low = 0;
  int high = s.size();
  reverse_s(s, low, high);
  int falg = 0;  //���������һ���ո��λ��
  int j = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '\0') {
      s[j--] = s[i];
    }
  }
  low = high;
  int p = high--;
  while (low >= 0) {
    while (s[p] != '\0') {
      p--;
    }
    low = p;
  }
  return s;
}

void removeExtraSpaces(string& s) {
  int slowIndex = 0, fastIndex = 0;  // �����ָ�룬��ָ��
  // ȥ���ַ���ǰ��Ŀո�
  while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
    fastIndex++;
  }
  for (; fastIndex < s.size(); fastIndex++) {
    // ȥ���ַ����м䲿�ֵ�����ո�
    if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] &&
        s[fastIndex] == ' ') {
      continue;
    } else {
      s[slowIndex++] = s[fastIndex];
    }
  }
  if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {  // ȥ���ַ���ĩβ�Ŀո�
    s.resize(slowIndex - 1);
  } else {
    s.resize(slowIndex);  // ���������ַ�����С
  }
}
int main() {
  string s;
  getline(cin, s);
  removeExtraSpaces(s);
  cout << s << endl;

  return 0;
}
