//Created on ...24/6/19
#include <iostream>
//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����

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