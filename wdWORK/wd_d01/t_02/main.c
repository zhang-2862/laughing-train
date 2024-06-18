#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//（a) 编写程序读一条消息，然后检查这条消息是否是回文（消息从左往右看和从右往左看是一样的）：
//
//Enter a message : He lived as a devil, eh ?
//Palindrome
//
//Enter a message : Madam, I am Adam.
//Not a palindrome
//
//忽略所有不是字母的字符。用索引来跟踪数组中的位置。
//
//（b）修改上述程序，使用指针代替索引来跟踪数组中的位置。

//题(a)
bool is_palindrome(const char* str,int lenth) {
	int low = 0;
	int high = lenth-1;
	while (low<high)
	{
		if (str[low] != str[high]) {
			return false;
		}
		low++;
		high--;
	}
	return true;
}

int read_message(char* str) {
	char c;
	int count=0;
	while ((c = getchar()) != '\n') {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (c >= 'A' && c <= 'Z') {
				c += 32;
			}
			str[count++] = c;
			if (count > 99) {
				break;
			}
		}
	}
	return count;
}

//题(b)
bool is_palindrome_b(const char* str, int lenth) {
	int low = 0;
	int high = lenth - 1;
	while (low < high)
	{
		if (*(str+low) != *(str+high)) {
			return false;
		}
		low++;
		high--;
	}
	return true;
}

int read_message_b(char* str) {
	char c;
	int count = 0;
	while ((c = getchar()) != '\n') {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (c >= 'A' && c <= 'Z') {
				c += 32;
			}
			*(str+count) = c;
			count++;
			if (count > 99) {
				break;
			}
		}
	}
	return count;
}



int main(void) {
	char str[100];

	printf("Enter a message: ");
	int lenth = read_message_b(str);

	if (is_palindrome_b(str,lenth)) {
		printf("Palindrome\n");
	}
	else {
		printf("Not a palindrome\n");
	}

	return 0;
}