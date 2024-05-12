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
			cout <<"�����������Ϊ�� " << l * l * l << endl;
		}
		if (shape) {
			cout << "�ó��������Ϊ: " << l * w * h << endl;
		}
	}
	void calculateS() {
		if (!shape) {
			cout << "�������ε����Ϊ�� " << l * l << endl;
		}
		if (shape) {
			cout << "�ó����ε����Ϊ�� " << 2 * (l * w + l * h + h * w) << endl;
		}
	}

private:
	double l;//��
	double w;//��
	double h;//��
	bool shape;//0��ʾ�����Σ�1��ʾ������
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
