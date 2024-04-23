#include <iostream>
using namespace std;
int arr[20];

int findInsertPos(int low,int high, int x) {
	int mid = (low + high) / 2;
	while (low<high)
	{
		mid = (low + high) / 2;
		if (arr[mid] >= x) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		if (x >= arr[mid] && x < arr[mid + 1]) {
			break;
		}
	}
	return low;
}

void insert(int pos, int n,int x) {

	for (int i = n; i >=pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	cout << "请输入想插入的数" << endl;
	int x;
	cin >> x;
	int pos=findInsertPos(0, n, x);
	//cout << "pos= " << pos << endl;
	insert(pos, n,x);

	for (int i = 0; i <= n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}

