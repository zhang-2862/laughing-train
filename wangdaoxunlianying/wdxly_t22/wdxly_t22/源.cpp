#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cout << "������a��b��ֵ" << endl;
	cin >> a >> b;
	cout << "a= " << a << " " << "b= " << b << endl;
	//a = a ^ b;
	//b = b ^ a;
	//a = a ^ b;
	a += b;
	b = a - b;
	a = a - b;
	cout << "����a��b" << endl;
	cout << "a= " << a << " " << "b= " << b << endl;


	system("pause");
	return 0;
}

