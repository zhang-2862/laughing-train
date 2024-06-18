#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YEAR 1970
#define MONTH 1
#define DAY 1
#define DAY_OF_WEEK 4

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

int get_days_defference(int year2,int month2,int day2) {
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int days_deference = 0;

	if (year2 - 1970 > 0) {
		year2 -= 1;
		//计算年差大于一当中的天数
		while (year2 - YEAR >= 1) {
			if (isLeapYear(year2)) {
				days_deference += 366;
			}
			else {
				days_deference += 365;
			}
			year2--;

		}

		//计算年差小于一当中的天数
		for (int i = MONTH + 1; i <= 12; i++) {
			days_deference += month_days[i];
		}
		for (int i = 1; i < month2; i++) {
			days_deference += month_days[i];
		}
		days_deference = days_deference + day2 + month_days[MONTH] - DAY + 1;

	}
	else {
		for (int i = MONTH + 1; i < month2; i++) {
			days_deference += month_days[i];
		}
		days_deference = days_deference + day2 + month_days[MONTH] - MONTH + 1;
	}
	return days_deference;
}

int main(void) {

	int year, month, day;
	
	scanf("%d%d%d", &year, &month, &day);

	int days_defference = get_days_defference(year, month, day);

	int day_of_week = days_defference % 7 + DAY_OF_WEEK;

	printf("day of week is: %d\n", day_of_week);

	return 0;
}