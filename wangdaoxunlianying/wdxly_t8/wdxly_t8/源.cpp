#include <iostream>
using namespace std;

int main() {
	float a = 0;
	float b = 0;
	float c = 0;
	cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a) {
		float aver = (a + b + c) / 2;
		float area = sqrt(aver * (aver - a) * (aver - b) * (aver - c));
		cout << "�������ε����Ϊ" << aver << endl;
		if (a == b && b == c) {
			cout << "���������ǵȱ�������" << endl;
		}
		else if (a == b || a == c || b == c) {
			cout << "���������ǵ���������" << endl;
		}
		else if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a){
			cout << "����������ֱ��������" << endl;
		}
	}
	else
	{
		cout << "�������������";
	}
	return 0;
}
