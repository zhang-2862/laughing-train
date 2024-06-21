#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//定义一个枚举类型Month，包含一年中的12个月份，并为每个月份分配一个从1开始的数字值。
//
//例如：January = 1，February = 2，依此类推....
//
//编写一个函数，接收Month类型的参数，返回该月份有多少天。

typedef enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	Octobe,
	November,
	December
}MONTH;

int get_days_of_month(MONTH month) {
	switch(month) {
		case 1:return 31;
		case 2:return 28;
		case 3:return 31;
		case 4:return 30;
		case 5:return 31;
		case 6:return 30;
		case 7:return 31;
		case 8:return 31;
		case 9:return 30;
		case 10:return 31;
		case 11:return 30;
		case 12:return 31;
	}
}

int main(void) {
	MONTH x;
	scanf("%d", &x);
	printf("x month has %d days",get_days_of_month(x));
	return 0;
}