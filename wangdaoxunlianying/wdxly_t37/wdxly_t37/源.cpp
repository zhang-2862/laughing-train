#include <iostream>
using namespace std;

class Triangle {
public:
	Triangle(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}
	double operator+(Triangle& t) {
		double s1 = (this->a + this->b + this->c) / 2;
		double s2 = (t.a + t.b + t.c) / 2;
		double area1 = sqrt(s1 * (s1 - this->a) * (s1 - this->b) * (s1 - this->c));
		double area2 = sqrt(s2 * (s2 - t.a) * (s2 - t.b) * (s2 - t.c));
		return area1 + area2;
	}
private:
	int a;
	int b;
	int c;
};

int main() {
	Triangle t1(3, 4, 5);
	Triangle t2(4, 5, 6);
	double sumArea = t1 + t2;
	cout << "t1+t2的总面积为： " << sumArea << endl;

	system("pause");
	return 0;
}
