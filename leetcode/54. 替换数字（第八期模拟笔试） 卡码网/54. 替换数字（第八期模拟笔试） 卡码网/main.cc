//Created on ...24/6/19
#include <iostream>

//54. �滻���֣��ڰ���ģ����ԣ�
//ʱ�����ƣ�1.000S  �ռ����ƣ�128MB
//��Ŀ����
//����һ���ַ��� s��������Сд��ĸ�������ַ������дһ�����������ַ����е���ĸ�ַ����ֲ��䣬����ÿ�������ַ��滻Ϊnumber�� ���磬���������ַ��� "a1b2c3"������Ӧ�ý���ת��Ϊ "anumberbnumbercnumber"��
//��������
//����һ���ַ��� s, s ������Сд��ĸ�������ַ���
//�������
//��ӡһ���µ��ַ���������ÿ�������ַ������滻Ϊ��number
//����ʾ��
//
//a1b2c3
//
//���ʾ��
//
//anumberbnumbercnumber
//
//��ʾ��Ϣ
//���ݷ�Χ��
//1 <= s.length < 10000��

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