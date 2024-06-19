#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//编写下面的函数：
//
//void remove_filename(char* url);
//
//url 指向一个包含以文件名结尾的 URL 字符串，例如 "http://www.knking.com/index.html"。函数需要移除文件名和前面的斜杠。(在上面的例子中，结果为 "http://www.knking.com"）。要求在函数中使用 "搜索字符串末尾" 的惯用法。
//
//	提示：把字符串中的最后一个斜杠替换为空字符。

void remove_filename(char* url) {
	while (*url) {
		url++;
	}
	url--;//让url指向倒数第一个不为‘\0’的字符
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