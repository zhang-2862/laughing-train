#include <iostream>
using namespace std;

int main() {
	char c;
	cin >> c;
	if (c >= 'A' && c <= 'Z') {
		cout << "���ַ��Ǵ�д��ĸ" << endl;
	}
	else if (c >= 'a' && c <= 'z') {
		cout << "���ַ���Сд��ĸ" << endl;
	}
	else
	{
		cout << "���ַ�����26��Ӣ����ĸ" << endl;
	}


	system("pause");
	return 0;
}

