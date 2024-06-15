#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//用户输入初始金额，利率和投资年数，程序将打印一张表格。表格将显示输入的利率以及紧随其后 4 个更高利率下的总金额。程序的会话如下：
//
//Enter initial balance : 100
//Enter interest rate : 6
//Enter number of years : 5
//
//Years    6 % 7 % 8 % 9 % 10 %
//1    106.00 107.00 108.00 109.00 110.00
//2    112.36 114.49 116.64 118.81 121.00
//3    119.10 122.50 125.97 129.50 133.10
//4    126.25 131.08 136.05 141.16 146.41
//5    133.82 140.26 146.93 153.86 161.05
int main(void) {
	double balance=0;
	int rate=0;
	int years=0;

	double arr_balance[5] = { 0 };

	printf("Enter initial balnce : ");
	scanf("%lf", &balance);

	printf("Enter interest rate : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &years);

	printf("\nYears ");
	for (int  i = 0; i < 5; i++)
	{
		printf("%4d%%  ", rate + i);
		arr_balance[i] = balance;
	}

	printf("\n");

	for (int year = 1; year <= years; year++)
	{
		printf("%3d  ", year);
		for (int i = 0; i < 5; i++)
		{
			arr_balance[i] += arr_balance[i] * (rate+i) / 100.0;
			printf("%7.2lf", arr_balance[i]);
		}
		printf("\n");
	}

	return 0;
}