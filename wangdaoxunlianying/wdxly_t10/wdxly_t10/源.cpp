#include <iostream>
using namespace std;

double transfor(double f) {
	double c = (f - 32) * 5 / 9;
	return c;
}

int main() {
	double f;
	cout << "�����뻪���¶�" << endl;
	cin >> f;
	double res;
	res=transfor(f);
	cout <<"�����¶�Ϊ�� " << res<<endl;
	system("pause");
	return 0;
}
