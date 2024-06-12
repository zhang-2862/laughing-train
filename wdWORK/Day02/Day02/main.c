#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_greatest_comdiv(int num1,int num2) {

	while (num1 % num2) {
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	return num2;
}

int main(void) {
	int num1;
	int denom1;


	int num2;
	int denom2;

	printf("Enter first fraction:");
	scanf("%d/%d", &num1, &denom1);

	printf("Enter second fraction:");
	scanf("%d/%d", &num2, &denom2);

	int num = num1 * denom2 + num2 * denom1;
	int denom = denom1 * denom2;

	int comdiv = get_greatest_comdiv(num, denom);
	
	if (denom / comdiv == 1) {
		printf("%d\n", num / comdiv);
	}
	else {
		printf("%d/%d\n", num / comdiv, denom / comdiv);
	}

	return 0;
}