#include <iostream>
#include <string>
using namespace std;

void get_1(string& str) {
	getline(cin, str);
}

void get_2(string& str) {
	cin >> str;
}

int main() {
	string str1;
	string str2;

	get_1(str1);
	get_2(str2);

	cout <<"一次读入一行： " << str1 << endl;
	cout << "一次读入一个词： " << str2 << endl;


	system("pause");
	return 0;
}
