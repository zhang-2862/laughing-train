#include <iostream>
using namespace std;

class Counter {
public:
	Counter(int a) {
		cnt = a;
	 }
	void inc() {
		cnt++;
	}
	void dec() {
		cnt--;
	}
	void showCnt() {
		cout << "��ǰ��������ֵΪ�� " << cnt<<endl;
	}

private:
	int cnt;
};

int main() {
	Counter counter(0);
	counter.inc();
	counter.inc();
	counter.showCnt();
	counter.dec();
	counter.showCnt();

	system("pause");
	return 0;
}
