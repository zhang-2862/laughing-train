#include <iostream>
using namespace std;

class Mammal {
public:
	virtual void speak() {
		cout << "�����ڽ�..." << endl;
	}
};

class Dog :public Mammal {
public:
	void speak() {
		cout << "С���ڽ�..." << endl;
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
