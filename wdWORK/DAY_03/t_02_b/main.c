#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];

int main(void) {
	printf("please input data amount : ");
	int n;
	scanf("%d", &n);

	printf("please input data now :\n");

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int Xor=0;

	for (int i = 0; i < n; i++)
	{
		Xor ^= arr[i];
	}

	//��Xor�Ķ����������һλ��Чλ
	int lsb = Xor & (-Xor);


	int res_1=0;
	int res_2=0;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i] & lsb)) {
			res_1 ^= arr[i];
		}
		else {
			res_2 ^= arr[i];
		}
	}

	printf("res_1 = %d, res_2 = %d\n",res_1,res_2);
	


	return 0;
}