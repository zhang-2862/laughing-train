#include <iostream>
using namespace std;

class Box
{
public:
	Box(double L) {
		l = L;
		shape = false;
	}
	Box(double L, double W, double H) {
		l = L;
		w = W;
		h = H;
		shape = true;
	}
	void calculateV() {
		if (!shape) {
			cout <<"该正方形体积为： " << l * l * l << endl;
		}
		if (shape) {
			cout << "该长方形体积为: " << l * w * h << endl;
		}
	}
	void calculateS() {
		if (!shape) {
			cout << "该正方形的面积为： " << l * l << endl;
		}
		if (shape) {
			cout << "该长方形的面积为： " << 2 * (l * w + l * h + h * w) << endl;
		}
	}

private:
	double l;//长
	double w;//宽
	double h;//高
	bool shape;//0表示正方形，1表示长方形
};


int main() {

	Box box1(5);
	Box box2(3, 4, 5);
	box1.calculateS();
	box1.calculateV();
	box2.calculateS();
	box2.calculateV();

	system("pause");
	return 0;
}
