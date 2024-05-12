#include<iostream>
#include <list>
#include <deque>

using namespace std;

void printIntDeque(deque<int>& ideq) {
	for (auto e : ideq) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	list<int> il{1,2,3,4,5,6,7,8,9,10};
	deque<int> id_odd;
	deque<int> id_eve;

	auto iter = il.begin();
	while (iter != il.end()) {
		if (*iter%2 == 0) {
			id_eve.push_back(*iter++);
		}
		else {
			id_odd.push_back(*iter++);
		}
	}
	cout << "����Ԫ��deque" << endl;
	printIntDeque(id_odd);
	cout << "ż��Ԫ��deque" << endl;
	printIntDeque(id_eve);
	return 0;
}