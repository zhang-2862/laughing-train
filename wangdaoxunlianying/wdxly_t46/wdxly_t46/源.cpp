#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (auto c : str) {
		if (!ispunct(c)) {
			cout << c;
		}	
	}
	cout << endl;


	system("pause");
	return 0;
}
