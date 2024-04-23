#include <iostream>
using namespace std;
char arr[10][10];
int sum = 0;//用来记录解法总数

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
			//若当前位置的45度斜线上或者横竖线上有皇后则返回false
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
	initArr(8);//初始化棋盘
	backQueen(0,8);//回溯查找N皇后位置
	cout <<"共有 " << sum <<" 种解法" << endl;//计算8皇后的解法总数
	system("pause");
	return 0;
}


