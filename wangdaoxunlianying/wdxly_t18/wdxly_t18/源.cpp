#include <iostream>
using namespace std;
int arr[5][5];
int main() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = i + 1 - j;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}


	system("pause");
	return 0;
}

