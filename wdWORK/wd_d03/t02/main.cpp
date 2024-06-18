#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}


int main(void) {
	int year1, month1, day1;
	int year2, month2, day2;

	scanf("%d%d%d", &year1, &month1, &day1);
	scanf("%d%d%d", &year2, &month2, &day2);

	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	int days_deference=0;

	if (year2 - year1 > 0) {
		year2 -= 1;
		//计算年差大于一当中的天数
		while (year2 - year1 >= 1) {
			if (isLeapYear(year2)) {
				days_deference += 366;
			}
			else {
				days_deference += 365;
			}
			year2--;

		}

		//计算年差小于一当中的天数
		for (int i = month1 + 1; i <= 12; i++) {
			days_deference += month_days[i];
		}
		for (int i = 1; i < month2; i++) {
			days_deference += month_days[i];
		}
		days_deference = days_deference + day2 + month_days[month1] - day1 + 1;

	}
	else {
		for (int i = month1+1; i < month2; i++) {
			days_deference += month_days[i];
		}
		days_deference = days_deference + day2  + month_days[month1] - day1 +1;
	}

	printf("%d\n", days_deference);

	return 0;
}