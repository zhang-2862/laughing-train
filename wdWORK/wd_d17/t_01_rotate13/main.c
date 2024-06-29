#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//请实现下面功能
//
//将一个文件读入程序，将其中的大小写字母右旋13个位置后，写入另一个文件。
//
//[A - Ma - m] 转换成[N - Zn - z]
//
//[N - Zn - z] 转换成[A - Ma - m]
//
//其余字符不变

int main(int argc, char* argv[]) {
	FILE* src = fopen(argv[1], "r");
	if (!src) {
		perror(argv[1]);
		exit(1);
	}
	FILE* dst = fopen("b.txt", "w");
	if (!dst) {
		perror("b.txt open failed!");
		fclose(src);
		exit(1);
	}
	int ch;
	while ((ch = fgetc(src)) != EOF) {

		if (('a' <= ch && ch<= 'm') || ('A' <= ch && ch<= 'M')) {
			ch += 13;
		}else if (('l' <= ch && ch<= 'z') || ('L' <= ch && ch<= 'Z')) {
			ch -= 13;
		}
		fputc(ch, dst);

	}
	fclose(src);
	fclose(dst);
	printf("rotate13 succeed!\n");
	return 0;
}
