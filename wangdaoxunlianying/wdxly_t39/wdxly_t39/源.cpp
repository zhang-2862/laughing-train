#include <iostream>
using namespace std;
#define PI 3.14

class Shape {
public:
	virtual void calculate() = 0;
};

class Rectangle :public Shape {
public:
	Rectangle(int x, int y) {
		length = x;
		width = y;
	}
	void calculate() {
		int area = length * width;
		cout << "长方形的面积是： " << area << endl;
	}
private:
	int length;
	int width;
};

class Trapezium :public Shape {
public:
	Trapezium(int x, int y, int z) {
		length = x;
		width = y;
		height = z;
	}
	void calculate() {
		double area= (length + width) * height / 2;
		cout << "梯形的面积是： " << area << endl;
	}
private:
	int length;
	int width;
	int height;
};

class Circle :public Shape{
public:
	Circle(int x) {
		radius = x;
	}
	void calculate() {
		double area = radius * radius * PI;
		cout << "梯形的面积是： " << area << endl;
	}
private:
	double radius;
};



int main() {
	Shape *shape;
	Rectangle r1(5,10);
	Trapezium t1(5, 10, 6);
	Circle c1(6);

	shape = &r1;
	shape->calculate();

	shape = &t1;
	shape->calculate();

	shape = &c1;
	shape->calculate();

	system("pause");
	return 0;
}
