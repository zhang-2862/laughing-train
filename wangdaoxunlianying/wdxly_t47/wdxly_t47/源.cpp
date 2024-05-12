#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(10,1);

	cout << "处理前： " << endl;
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;

	for (auto i = v.begin(); i !=v.end() ; i++)
	{
		(*i) *= 2;
	}

	cout << "处理后： " << endl;
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
