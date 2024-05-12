#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	string s2;
	
	cin >> s1 >> s2;


	//修改前：
	//string s3 = s1 + s2;
	//cout << s3<<endl;
	
	//修改后：
	string s3 = s1 + " " + s2;
	cout << s3 << endl;


	system("pause");
	return 0;
}
