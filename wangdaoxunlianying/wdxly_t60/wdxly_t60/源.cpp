#include <iostream>
#include<vector>

using namespace std;

void bubleSort(vector<int> &v) {
	for (int i = v.size()-1; i >=0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main() {
	vector<int> v{ 10,22,44,22,19,18,17,33,66,77 };
	bubleSort(v);
	for (const auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}