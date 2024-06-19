#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现自己版本的 strcmp
//
//int my_strcmp(const char* s1, const char* s2);
int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		s1++;
		s2++;
	}//找到第一个不相等的位置
	return *s1 - *s2;
}
int main(void) {
	char str1[50];
	char str2[50];
	printf("please input string1\n");
	gets(str1);
	printf("\nplease input string2\n");
	gets(str2);

	printf("\n");

	int res = my_strcmp(str1, str2);
	if (res > 0) {
		printf("str1 > str2\n");
	}
	else if (res < 0) {
		printf("str1 < str2\n");
	}
	else {
		printf("str1 = str2");
	}



	return 0;
}