#include <iostream>
using namespace std;
int arr[10];

void bubleSort() {
	bool flag=false;
	for (int i = 0; i < 9; i++)
	{
		flag = true;
		for (int j = 9; j > i; j--)
		{
			if (arr[j] > arr[j - 1]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				flag = false;
			}
		}
		if (flag) {//���ĳ��ð��δ��������������ǰ��������
			return;
		}
	}
}

int main(){
	cout << "������ʮ������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	bubleSort();
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	system("pause");
	return 0;
}


