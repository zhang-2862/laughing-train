#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����һ��ö������Month������һ���е�12���·ݣ���Ϊÿ���·ݷ���һ����1��ʼ������ֵ��
//
//���磺January = 1��February = 2����������....
//
//��дһ������������Month���͵Ĳ��������ظ��·��ж����졣

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