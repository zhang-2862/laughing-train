#include <iostream>
using namespace std;
#define PI 3.14
int main() {
	double r;
	double h;
	cout << "������뾶�͸�" << endl;
	cin >> r >> h;
	double s = r * r * PI;
	double v = s * h;
	cout << "Բ��������Ϊ�� " << s<<endl;
	cout << "Բ�������Ϊ�� " << s<<endl;

	system("pause");
	return 0;
}

