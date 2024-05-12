#include <iostream>
using namespace std;
#define PI 3.14
class Base {
public:
	virtual double calArea() = 0;
};

class Triangle :public Base{
public:
	Triangle(double x, double y, double z) {
		a = x;
		b = y;
		c = z;
	}
	double calArea() {
		double s = (a + b + c) / 2;
		double area = sqrt(s * (s - a) * (s - b) * (s - c));
		return area;
	}
private:
	double a;
	double b;
	double c;
};

class Square :public Base {
public:
	Square(double x) {
		a = x;
	}
	double calArea() {
		return a * a;
	}
private:
	double a;
};

class Circle :public Base {
public:
	Circle(double x) {
		r = x;
	}
	double calArea() {
		return PI * r * r;
	}
private:
	double r;
};

int main() {
	Base* base;

	Triangle tri(3, 4, 5);
	Square squ(5.5);
	Circle cir(6.6);

	base = &tri;
	cout<<base->calArea()<<endl;

	base = &squ;
	cout << base->calArea()<<endl;

	base = &cir;
	cout << base->calArea()<<endl;


	system("pause");
	return 0;
}
