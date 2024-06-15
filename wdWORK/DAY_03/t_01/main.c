#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�����뿪��һ�����˳��򡣳���Ϊ�û��ṩѡ��˵�������˻������˻��ϴ�Ǯ�����˻���ȡǮ����ʾ��ǰ���˳�����ѡ����ֱ������� 0��1��2��3 �� 4 ��ʾ������ĻỰ����������
//
//* **checkbook - balancing program * **
//Commands: 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit
//
//Enter command : 1
//Enter amount of credit : 1000.0
//Enter command : 2
//Enter amount of debit : 100.0
//Enter command : 3
//Current balance : $900.00
//Enter command : 9
//Commands : 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit
//
//Enter command : 0
//Enter command : 3
//Current balance : $0.00
//Enter command : 4
int main(void) {
	printf("* **checkbook - balancing program * **\n");
	printf("Commands: 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit\n\n");

	double sum = 0;
	double amount = 0;
	int select;
	while (1)
	{
		printf("Enter command : ");
		scanf("%d", &select);

		switch (select)
		{
		case 0:
			sum = 0;
			break;
		case 1:
		{
			printf("Enter amount of credit : ");
			scanf("%lf", &amount);

			sum += amount;
			break;
		}
		case 2:
		{
			printf("Enter amount of debit : ");
			scanf("%lf", &amount);

			sum -= amount;
			break;
		}
		case 3:
			printf("Current balance : $%.2lf\n",sum);
			break;
		case 4:
			exit(0);
		default:
			break;
		}
	}
	
	return 0;
}