#include <iostream>
#include<string>
using namespace std;

int main() {
	int c_num=0;
	int b_num=0;
	int n_num=0;
	int e_num=0;
	string str;
	getline(cin, str);
	for(int i=0;i<str.size();i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			c_num++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			c_num++;
		}
		else if (str[i] == ' ') {
			b_num++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			n_num++;
		}
		else
		{
			e_num++;
		}
	}
	cout << "英文字母个数为： " << c_num << endl;
	cout << "空格个数为： " << b_num << endl;
	cout << "数字个数为： " << n_num << endl;
	cout << "其他字符个数为： " << e_num << endl;


	system("pause");
	return 0;
}

