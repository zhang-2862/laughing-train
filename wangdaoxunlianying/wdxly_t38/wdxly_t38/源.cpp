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
	cout << "������a+b֮�͵���" << add(a, b) << endl;
	cout <<"������c+d֮�͵���" << add(c, d) << endl;

	system("pause");
	return 0;
}
