#include <iostream>
using namespace std;

double calculate(int n) {
	double sum = 0;
	int k = 2;
	for (int i = 0; i < 20; i++)
	{
		sum += 1.0 / k;
		k += 2;
	}
	return sum;
}


int main() {
	double res=0;
	res=calculate(20);
	cout << res << endl;

	system("pause");
	return 0;
}