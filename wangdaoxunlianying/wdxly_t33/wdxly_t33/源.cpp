#include <iostream>
using namespace std;

class Tree {
public:
	void grow(int years) {
		ages = years;
	}
	void showAge() {
		cout << "Ê÷µÄÄêÁäÊÇ£º " << ages << endl;
	}
private:
	int ages;
};

int main() {
	Tree tree;
	tree.grow(99);
	tree.showAge();
	system("pause");
	return 0;
}
