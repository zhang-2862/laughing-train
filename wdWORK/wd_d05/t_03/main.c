#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long next_fib(void) {
	static long long pre = 0;
	static long long cur = 1;
	long long next = pre + cur;
	pre = cur;
	cur = next;
	return pre;
}

int main(void) {
	// foo();	// Fibnacii: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
	printf("next_fib() = %lld\n", next_fib());	// 1
	printf("next_fib() = %lld\n", next_fib());	// 1
	printf("next_fib() = %lld\n", next_fib());	// 2
	printf("next_fib() = %lld\n", next_fib());	// 3
	printf("next_fib() = %lld\n", next_fib());	// 5
	for (int i = 0; i < 50; i++)
	{
		printf("next_fib() = %lld\n", next_fib());	
	}

	return 0;
}