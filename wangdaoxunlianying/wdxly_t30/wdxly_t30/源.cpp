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
	cout << "���г�ʼ״̬�� ";
	printArr(n);
	cout << endl;
	k = k - 1;//�������±�ƥ��
	while (n)
	{
		cout << arr[(k + m - 1) % n] <<" ����" << endl;//����
		
		for (int i = (k + m - 1) % n; i < n; i++)//�������˵�λ�����
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
	cout << "����������n���ˣ���ʼ���k���Լ�����m" << endl;
	cin >> n >> k >> m;
	initArr(n);
	deQue(n,k,m);
	system("pause");
	return 0;
}
