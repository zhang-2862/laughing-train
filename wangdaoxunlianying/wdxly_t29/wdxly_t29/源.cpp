#include <iostream>
using namespace std;

int calculate(string str) {

	int arr[4] = { 8,4,2,1 };//用来储存位权
	int sum = 0;
	for (int i = 0; i < 16; i++)
	{
		sum += (str[i] - '0') * arr[i % 4];
	}
	return sum;
}

int main() {
	string str;
	cin >> str;
	int res;
	res=calculate(str);
	cout << res << endl;
	system("pause");
	return 0;
}