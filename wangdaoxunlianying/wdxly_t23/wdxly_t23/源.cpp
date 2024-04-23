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
	bool flag = false;//当前处理字符为字母则flag为真
	for (int i = 0; i < str.size(); i++)
	{
		if (isletter(str[i])) {
			flag = true;
		}
		else {
			flag = false;
		}
		if (flag == true && !isletter(str[i+1])) {//当前处理的是字母而下一个不是字母则判定为一个单词
			num++;
		}
	}
	cout <<"单词数为： " << num << endl;

	system("pause");
	return 0;
}

