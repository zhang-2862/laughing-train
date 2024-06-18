#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n,char start,char middle,char target) {
	if (n == 1) {
		printf("%c -> %c\n",start,target);
		return;
	}
	hanoi(n - 1, start, target, middle);
	printf("%c -> %c\n", start,target);
	hanoi(n - 1, middle, start, target);
}


int main(void) {
	int n = 0;
	scanf("%d", &n);
	printf("need move %d times.\n", (1 << n) - 1);
	hanoi(n, 'A', 'B', 'C');

	return 0;
}