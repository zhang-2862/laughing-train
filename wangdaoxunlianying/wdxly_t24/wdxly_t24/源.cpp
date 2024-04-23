#include <iostream>
using namespace std;
char arr[10][10];
int sum = 0;//������¼�ⷨ����

void initArr(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ',';
		}
	}
}

bool isValid(int x, int y,int n) {
	for (int k = 0; k < n; k++)
	{
		for (int l = 0; l < n; l++)
		{
			//����ǰλ�õ�45��б���ϻ��ߺ��������лʺ��򷵻�false
			if ( k == x || l == y || (k + l == x + y) || (l - k == y - x) ) {
				if (arr[k][l] == 'Q') {
					return false;
				}
			}
		}
	}
	return true;
}

void printArr(int n) {
	sum++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "---------------------" << endl;
	cout << endl;
}

void backQueen(int row,int n) {
	if (row == n) {
		printArr(n);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isValid(i,row,n))
		{
			arr[i][row] = 'Q';
			backQueen(row + 1,n);
			arr[i][row] = ',';
		}
	}
}

int main() {
	initArr(8);//��ʼ������
	backQueen(0,8);//���ݲ���N�ʺ�λ��
	cout <<"���� " << sum <<" �ֽⷨ" << endl;//����8�ʺ�Ľⷨ����
	system("pause");
	return 0;
}


