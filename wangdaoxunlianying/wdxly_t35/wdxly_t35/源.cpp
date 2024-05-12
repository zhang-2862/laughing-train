#include <iostream>
using namespace std;

class Plural {
public:
	friend Plural operator+(Plural& p1, Plural& p2);
	Plural() {

	}
	Plural(int a, int b) {
		realp = a;
		imagp = b;
	}
	int getRealp() {
		return realp;
	}
	int getImagp() {
		return imagp;
	}
private:
	int realp;
	int imagp;
};

Plural operator+(Plural& p1,Plural& p2) {
	Plural p;
	p.realp = p1.realp + p2.realp;
	p.imagp = p1.imagp + p2.imagp;
	return p;
}

int main() {
	Plural p1(3, 5);
	Plural p2(2, 5);
	Plural p3 = p1 + p2;
	cout << "p3的实部为： " << p3.getRealp() << "   虚部为： " << p3.getImagp()<<endl;

	system("pause");
	return 0;
}
