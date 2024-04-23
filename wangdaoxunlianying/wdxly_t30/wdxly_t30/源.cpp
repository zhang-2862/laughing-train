#include <iostream>
using namespace std;

int arr[100];

void initArr(int n) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
}
void printArr(int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void deQue(int n, int k, int m) {
	cout << "队列初始状态： ";
	printArr(n);
	cout << endl;
	k = k - 1;//与数组下标匹配
	while (n)
	{
		cout << arr[(k + m - 1) % n] <<" 出队" << endl;//出队
		
		for (int i = (k + m - 1) % n; i < n; i++)//将出队人的位置填充
		{
			arr[i] = arr[i + 1];
		}
		k = (k + m - 1) % n;
		n--;
		printArr(n);
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	int k;
	int m;
	cout << "请依次输入n个人，起始编号k，以及报数m" << endl;
	cin >> n >> k >> m;
	initArr(n);
	deQue(n,k,m);
	system("pause");
	return 0;
}
