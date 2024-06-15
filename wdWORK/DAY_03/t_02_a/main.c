#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int n;
	printf("please input data amount: ");
	scanf("%d", &n);

	printf("please input data\n");
	

	int res=0;
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		res ^= x;
	}
	printf("%d\n", res);
	system("pause");
	return 0;
}