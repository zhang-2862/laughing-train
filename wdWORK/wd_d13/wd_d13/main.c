#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//����һ��������Сд��ĸ���ַ�������ȥ���ַ����е��ظ���ĸ��ʹ��ÿ����ĸֻ����һ�Ρ�������ĸ��С���������
//
//ʾ����
//���룺"bcabc"
//�����"abc"
//
//// ���ַ������޸�
//void remove_duplicate_and_sort(char* str);

bool map[26] = { false };

void remove_duplicate_and_sort(char* str) {
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		map[str[i] - 'a'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (map[i] == true) {
			printf("%c",'a' + i);
		}
	}
}


int main(void) {
	char str[64];
	scanf("%s", str);
	remove_duplicate_and_sort(str);

	return 0;
}