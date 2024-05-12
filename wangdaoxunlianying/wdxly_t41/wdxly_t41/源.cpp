#include <iostream>
using namespace std;

class Mammal {
public:
	virtual void speak() {
		cout << "动物在叫..." << endl;
	}
};

class Dog :public Mammal {
public:
	void speak() {
		cout << "小狗在叫..." << endl;
	}
};

int main() {
	Mammal* mammal;
	Dog dog;
	mammal = &dog;
	mammal->speak();

	system("pause");
	return 0;
}
