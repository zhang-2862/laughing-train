#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	string s2;
	
	cin >> s1 >> s2;


	//�޸�ǰ��
	//string s3 = s1 + s2;
	//cout << s3<<endl;
	
	//�޸ĺ�
	string s3 = s1 + " " + s2;
	cout << s3 << endl;


	system("pause");
	return 0;
}
