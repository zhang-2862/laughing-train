#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class MyString {
public:
	MyString(char *Head) {
		strcpy(head, Head);
	}

	void reverse() {
		int len = strlen(head);
		for (int i = 0; i < len/2; i++)
		{
			char temp = head[i];
			head[i] = head[len - i-1];
			head[len - i-1] = temp;
		}
	}

	void print() {
		cout << head << endl;
	}

private:
	char head[100];
};

int main() {

	char str[15]= "ILOVECHINESE";
	MyString myString(str);
	myString.print();
	myString.reverse();
	myString.print();

	system("pause");
	return 0;
}
