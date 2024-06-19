#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现自己版本的 strlen
//
//size_t my_strlen(const char* s);

size_t my_strlen(const char* s) {
	const char* p=s;
	while (*p) {
		p++;
	}
	return p-s;
}

int main(void) {
	char str[40];
	printf("please input a sting\n");
	gets(str);
	int lenth = my_strlen(str);
	printf("string length is %d", lenth);
	return 0;
}