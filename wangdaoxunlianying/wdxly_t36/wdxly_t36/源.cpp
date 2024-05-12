#include <iostream>
using namespace std;

class Time {
public:
	Time(int a,int b){
		minute = a;
		sec = b;
	}
	Time& operator++() {
		if (this != NULL) {
			if (++this->sec / 60 == 1) {
				this->minute++;
			}
			this->sec = (this->sec) % 60;
		}
		return *this;
	}
	int getMin() {
		return minute;
	}
	int getSec() {
		return sec;
	}
private:
	int minute;
	int sec;
};

int main() {
	Time t(24,59);
	cout << t.getMin() << ":" << t.getSec() << endl;//++֮ǰ
	++t;
	cout << "++��: " << endl;
	cout << t.getMin() << ":" << t.getSec() << endl;//++֮��

	system("pause");
	return 0;
}
