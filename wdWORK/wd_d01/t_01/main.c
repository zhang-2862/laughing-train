#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��a) ��д�����һ����Ϣ��Ȼ�������ӡ������Ϣ��
//
//Enter a message : Don't get mad, get even.
//Reversal is : .neve teg, dam teg t'noD
//
//��ʾ��һ�ζ�ȡ��Ϣ�е�һ���ַ�����getchar�����������Ұ���Щ��ĸ�洢�������У����������˻��߶����ַ� '\n' ʱֹͣ��������
//
//��b) �޸�����������ָ�������������������ĵ�ǰλ�á�

//�⣨a��
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

// �⣨b��
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