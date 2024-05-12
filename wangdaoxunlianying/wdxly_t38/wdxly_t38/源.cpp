#include <iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}

int main() {
	int a = 2;
	int b = 3;
	double c = 2.72;
	double d = 7.33;
	cout << "整型数a+b之和等于" << add(a, b) << endl;
	cout <<"浮点数c+d之和等于" << add(c, d) << endl;

	system("pause");
	return 0;
}
