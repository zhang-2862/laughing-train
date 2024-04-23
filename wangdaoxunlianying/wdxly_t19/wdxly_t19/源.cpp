#include <iostream>
using namespace std;

long sum(int n) {
	if (n == 1) {
		return 12;
	}
	return sum(n - 1) + n * 10 + 2;
}

int main() {
	int n;
	cin >> n;
	cout<<sum(n)<<endl;

	system("pause");
	return 0;
}

