#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str1[] = "I LOVE C++";
	char str2[] = "C++ IS BEST";

	string s1 = "I LOVE C++";
	string s2 = "C++ IS BEST";

	if (strcmp(str2, str1)>0) {
		cout << "str1´óÓÚstr2" << endl;
	}
	if (s1 > s2) {
		cout << "s1>s2" << endl;
	}


	system("pause");
	return 0;
}
