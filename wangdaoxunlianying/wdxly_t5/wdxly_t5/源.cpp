#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x >= 90 && x <= 100) {
		cout << "A�����㣩";
	}
	else if (x >= 80) {
		cout << "B�����ã�";
	}
	else if (x >= 70) {
		cout << "C���еȣ�";
	}
	else if (x >= 60) {
		cout << "D(�ϸ�)";
	}
	return 0;
}
