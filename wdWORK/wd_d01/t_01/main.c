#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//（a) 编写程序读一条消息，然后逆序打印这条消息：
//
//Enter a message : Don't get mad, get even.
//Reversal is : .neve teg, dam teg t'noD
//
//提示：一次读取消息中的一个字符（用getchar函数），并且把这些字母存储在数组中，当数组满了或者读到字符 '\n' 时停止读操作。
//
//（b) 修改上述程序，用指针代替整数来跟踪数组的当前位置。

//题（a）
int read_message(char* str) {
	char c;
	int count=0;
	while ((c=getchar())!='\n')
	{
		str[count++] = c;
		if (count > 98) {
			break;
		}
	}
	str[count] = '\0';
	return count;
}

void print_message(const char* str,int count) {
	while (count--)
	{
		printf("%c",str[count]);
	}
}

// 题（b）
int read_message_b(char* str) {
	char c;
	int count = 0;
	while ((c = getchar()) != '\n')
	{
		*(str+count) = c;
		count++;
		if (count > 98) {
			break;
		}
	}
	*(str+count) = '\0';
	return count;
}

void print_message_b(const char* str, int count) {
	while (count--)
	{
		printf("%c",*(str+count));
	}
}


int main(void) {
	char str[100];

	printf("Enter a message : ");
	int cnt=read_message(str);
	printf("Reversal is : ");
	print_message(str, cnt);

	//int cnt_b = read_message_b(str);
	//print_message_b(str, cnt_b);

	return 0;
}