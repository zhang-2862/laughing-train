#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//给定一个仅包含小写字母的字符串，请去除字符串中的重复字母，使得每个字母只出现一次。并按字母从小到大输出。
//
//示例：
//输入："bcabc"
//输出："abc"
//
//// 在字符串上修改
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