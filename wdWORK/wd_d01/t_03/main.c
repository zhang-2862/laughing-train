#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//��д�����ҳ�һ�鵥������С���ʺ���󵥴ʡ�
//���û�����4����ĸ�ĵ���ʱ������ֹͣ���롣
//�������е��ʶ�������20����ĸ������Ự���£�
//
//Enter word : dog
//Enter word : zebra
//Enter word : rabbit
//Enter word : catfish
//Enter word : walrus
//Enter word : cat
//Enter word : fish
//
//Smallest word : cat
//Largest word : zebra
//
//��ʾ��ʹ��������Ϊ smallest_word �� largest_word ���ַ������ֱ��¼��С���ʺ���󵥴ʡ�
//�û�ÿ����һ���µ��ʣ���Ҫ�� strcmp ������ smallest_word �� largest_word ���бȽϡ�
//�� strlen �����ж��û��Ƿ������� 4 ����ĸ�ĵ���

int main(void) {
	char str[20];
	char smallest_word[20]="zzzzzzzzzz";
	char largest_word[20] = "";


	while (true) {
		printf("Enter word: ");
		scanf("%s", str);
		if (strcmp(str, smallest_word) < 0) {
			strcpy(smallest_word, str);
		}
		else if (strcmp(str, largest_word)>0) {
			strcpy(largest_word, str);
		}
		if (strlen(str) == 4) {
			break;
		}
	}
	printf("\n");
	printf("Smallest word: %s\n", smallest_word);
	printf("largest word: %s\n", largest_word);

	return 0;
}