#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//��ʵ�����湦��
//
//��һ���ļ�������򣬽����еĴ�Сд��ĸ����13��λ�ú�д����һ���ļ���
//
//[A - Ma - m] ת����[N - Zn - z]
//
//[N - Zn - z] ת����[A - Ma - m]
//
//�����ַ�����

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
