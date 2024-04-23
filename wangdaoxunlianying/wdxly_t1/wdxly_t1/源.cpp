#include<iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x < 5) {
		cout << x;
	}
	else if(x<15)
	{
		cout << x + 6;
	}
	else if(x>=15)
	{
		cout << x - 6;
	}
	

	return 0;
}
