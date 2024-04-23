#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x >= 90 && x <= 100) {
		cout << "A（优秀）";
	}
	else if (x >= 80) {
		cout << "B（良好）";
	}
	else if (x >= 70) {
		cout << "C（中等）";
	}
	else if (x >= 60) {
		cout << "D(合格)";
	}
	return 0;
}
