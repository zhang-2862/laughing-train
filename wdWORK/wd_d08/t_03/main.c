#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//请实现自己版本的 strcpy
//
//char* my_strcpy(char* s1, const char* s2);

char* my_strcpy(char* s1, const char* s2) {
	while (*s1++ = *s2++)
		;
	return s1;
}
int main(void) {
	char src[50];
	char des[50];
	printf("please input source string\n");
	gets(src);
	printf("\nplease input destination string\n");
	gets(des);

	my_strcpy(des, src);

	printf("\nafter copy,the destination string is: \n");
	puts(des);
	printf("\n");
	return 0;
}