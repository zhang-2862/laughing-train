#include <iostream>
using namespace std;

int monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	int year=0;
	int month=0;
	int day=0;
	int hour=0;
	int minute=0;
	int second=0;
	cout << "请依次输入年月日时分秒" << endl;
	cin >> year >> month >> day >> hour >> minute >> second;
	if (++second >= 60) {
		minute++;
	}
	second = second  % 60;
	if (minute >= 60) {
		hour++;
	}
	minute = minute % 60;
	if (hour >= 24) {
		day++;
	}
	hour = hour % 24;
	if (isLeapYear (year) && month==2) {
		if (day > (monthday[month - 1] + 1)) {
			day = 1;
			month++;
		}
	}
	else
	{
		if (day > monthday[month - 1]) {
			day = 1;
			month++;
		}
	}
	if (month > 12) {
		year++;
		month = month % 12;
	}

	cout << year << "年" << month << "月" << day << "日"
		<< hour << "时" << minute << "分" << second << "秒"<<endl;

	system("pause");
	return 0;
}

