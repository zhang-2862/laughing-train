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
		cout << "该三角形的面积为" << aver << endl;
		if (a == b && b == c) {
			cout << "该三角形是等边三角形" << endl;
		}
		else if (a == b || a == c || b == c) {
			cout << "该三角形是等腰三角形" << endl;
		}
		else if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a){
			cout << "该三角形是直角三角形" << endl;
		}
	}
	else
	{
		cout << "不能组成三角形";
	}
	return 0;
}
