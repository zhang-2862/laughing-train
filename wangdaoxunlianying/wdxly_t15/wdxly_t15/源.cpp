#include <iostream>
using namespace std;

int main() {
	char c;
	cin >> c;
	if (c >= 'A' && c <= 'Z') {
		cout << "该字符是大写字母" << endl;
	}
	else if (c >= 'a' && c <= 'z') {
		cout << "该字符是小写字母" << endl;
	}
	else
	{
		cout << "该字符不是26个英文字母" << endl;
	}


	system("pause");
	return 0;
}

