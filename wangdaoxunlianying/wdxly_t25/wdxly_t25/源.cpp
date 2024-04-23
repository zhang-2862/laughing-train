#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	char str1[30];
	char str2[30];
	cin.getline(str1, 30);
	cin.getline(str2, 30);
	str1[11] = '\0';
	str2[17] = '\0';
	strcat(str1, &str2[4]);
	cout << str1 << endl;
	system("pause");
	return 0;
}


