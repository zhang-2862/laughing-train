#include <iostream>
using namespace std;

int main() {
	int a;
	int max = -1;
	int min = 99999;
	cin >> a;
	while (a>=0)
	{
		if (a > max) {
			max = a;
		}
		if (a < min) {
			min = a;
		}
		cin >> a;
	}
	cout << "最高成绩： " << max;
	cout <<"最低成绩： " << min;

	return 0;
}
