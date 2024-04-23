#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cout << "请输入a和b的值" << endl;
	cin >> a >> b;
	cout << "a= " << a << " " << "b= " << b << endl;
	//a = a ^ b;
	//b = b ^ a;
	//a = a ^ b;
	a += b;
	b = a - b;
	a = a - b;
	cout << "交换a和b" << endl;
	cout << "a= " << a << " " << "b= " << b << endl;


	system("pause");
	return 0;
}

