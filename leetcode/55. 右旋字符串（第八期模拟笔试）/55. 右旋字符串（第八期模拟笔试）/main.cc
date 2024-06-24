//Created on ...24/6/22
#include <iostream>

using namespace std;

//��Ŀ����
//
//�ַ���������ת�����ǰ��ַ���β�������ɸ��ַ�ת�Ƶ��ַ�����ǰ�档����һ���ַ��� s ��һ�������� k�����дһ�����������ַ����еĺ��� k ���ַ��Ƶ��ַ�����ǰ�棬ʵ���ַ���������ת������ 
//
//���磬���������ַ��� "abcdefg" ������ 2������Ӧ�ý���ת��Ϊ "fgabcde"��
//��������
//���빲�������У���һ��Ϊһ�������� k����������ת��λ�����ڶ���Ϊ�ַ��� s��������Ҫ��ת���ַ�����
//�������
//�����һ�У�Ϊ����������ת��������ַ�����
//����ʾ��
//
//2
//abcdefg
//
//���ʾ��
//
//fgabcde
//
//��ʾ��Ϣ
//���ݷ�Χ��
//1 <= k < 10000,
//1 <= s.length < 10000;

void reverse_string(string& s, int start, int end) {
    while (start < end) {
        char temp = s[end];
        s[end] = s[start];
        s[start] = temp;
        start++;
        end--;
    }
}

void rightHandedString(string& s, int k) {
    reverse_string(s, 0, s.size() - 1);
    reverse_string(s, 0, k - 1);
    reverse_string(s, k, s.size() - 1);
}

int main() {
    int k;
    string s;
    cin >> k >> s;

    rightHandedString(s, k);

    cout << s;
    return 0;
}