#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��д����ĺ�����
//
//void remove_filename(char* url);
//
//url ָ��һ���������ļ�����β�� URL �ַ��������� "http://www.knking.com/index.html"��������Ҫ�Ƴ��ļ�����ǰ���б�ܡ�(������������У����Ϊ "http://www.knking.com"����Ҫ���ں�����ʹ�� "�����ַ���ĩβ" �Ĺ��÷���
//
//	��ʾ�����ַ����е����һ��б���滻Ϊ���ַ���

void remove_filename(char* url) {
	while (*url) {
		url++;
	}
	url--;//��urlָ������һ����Ϊ��\0�����ַ�
	while ((*url) != '/') {
		url--;
	}
	*url = '\0';
}

int main(void) {
	char str[40];
	scanf("%s", str);
	remove_filename(str);
	puts(str);
	return 0;
}