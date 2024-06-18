#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int year;
	int month;
	int day;

	int flag;//用来标识是否为闰年

	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d%d%d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		flag = 1;
	}
	else {
		flag = 0;
	}
	if (month == 2 && flag==1) {
		month_days[2] = 29;
	}
	if (day + 1 > month_days[month]) {
		day = 1;
		month++;
		if (month + 1 > 12) {
			month = 1;
			year++;
		}
	}
	else {
		day++;
	}

	//将二月天数恢复默认
	month_days[2] = 28;

	printf("%d/%d/%d", year, month, day);
	return 0;
}