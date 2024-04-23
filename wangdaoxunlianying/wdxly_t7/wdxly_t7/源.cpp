#include <iostream>
using namespace std;
int arr[20];
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n/2; i++)
	{
		swap(arr[i], arr[n - 1 - i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	return 0;
}
