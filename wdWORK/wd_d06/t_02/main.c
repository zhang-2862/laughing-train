#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int joseph(int n, int m) {
	if (n == 1) {
		return 0;
	}
	
	return (joseph(n - 1,m) + m) % n;
}

int main(void) {
	int n, m;
	printf("�����������������Լ�ÿ�����˴���һ��\n");
	scanf("%d%d", &n, &m);

	int num = joseph(n, m)+1;
	printf("The number of those who survived is %d\n", num);

	return 0;
}