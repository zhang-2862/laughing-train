#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int num80 = 0;
	int num60 = 0;
	for (int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		sum += x;
		if (x >= 80) {
			num80++;
		}
		if (x<60)
		{
			num60++;
		}
	}
	double aver = sum / 10;
	cout << "80������������ " << num80 << endl;
	cout << "������������� " << num60 << endl;
	cout << "ƽ��ֵ�� " << aver<<endl;


	system("pause");
	return 0;
}

