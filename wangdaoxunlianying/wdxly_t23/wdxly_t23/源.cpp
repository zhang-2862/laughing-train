#include <iostream>
#include<string>
using namespace std;

bool isletter(char x) {
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) {
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	string str;
	getline(cin, str);
	int num = 0;
	bool flag = false;//��ǰ�����ַ�Ϊ��ĸ��flagΪ��
	for (int i = 0; i < str.size(); i++)
	{
		if (isletter(str[i])) {
			flag = true;
		}
		else {
			flag = false;
		}
		if (flag == true && !isletter(str[i+1])) {//��ǰ���������ĸ����һ��������ĸ���ж�Ϊһ������
			num++;
		}
	}
	cout <<"������Ϊ�� " << num << endl;

	system("pause");
	return 0;
}

