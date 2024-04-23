#include <iostream>
using namespace std;

double transfor(double f) {
	double c = (f - 32) * 5 / 9;
	return c;
}

int main() {
	double f;
	cout << "请输入华氏温度" << endl;
	cin >> f;
	double res;
	res=transfor(f);
	cout <<"摄氏温度为： " << res<<endl;
	system("pause");
	return 0;
}
