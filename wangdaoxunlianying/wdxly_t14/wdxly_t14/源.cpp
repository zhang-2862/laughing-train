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
	cout << "80分以上人数： " << num80 << endl;
	cout << "不及格的人数： " << num60 << endl;
	cout << "平均值： " << aver<<endl;


	system("pause");
	return 0;
}

