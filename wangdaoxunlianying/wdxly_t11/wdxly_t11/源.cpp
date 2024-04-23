#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout <<n<< "=1";
	for (int  i = 2; i <= n; )
	{
		if (n % i == 0) {
			cout << "*" << i;
			n /= i;
			continue;
		}
		i++;
	}
	cout << endl;


	system("pause");
	return 0;
}
