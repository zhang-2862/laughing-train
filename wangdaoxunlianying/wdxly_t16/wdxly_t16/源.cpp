#include <iostream>
using namespace std;
#define PI 3.14
int main() {
	double r;
	double h;
	cout << "请输入半径和高" << endl;
	cin >> r >> h;
	double s = r * r * PI;
	double v = s * h;
	cout << "圆柱体底面积为： " << s<<endl;
	cout << "圆柱体体积为： " << s<<endl;

	system("pause");
	return 0;
}

