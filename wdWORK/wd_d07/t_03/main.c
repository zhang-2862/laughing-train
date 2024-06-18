#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//编写程序找出一组单词中最小单词和最大单词。
//当用户输入4个字母的单词时，程序停止读入。
//假设所有单词都不超过20个字母。程序会话如下：
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
//提示：使用两个名为 smallest_word 和 largest_word 的字符串来分别记录最小单词和最大单词。
//用户每输入一个新单词，都要用 strcmp 把它与 smallest_word 和 largest_word 进行比较。
//用 strlen 函数判断用户是否输入了 4 个字母的单词

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