#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//https://leetcode.cn/problems/h-index-ii/description/

//275. H ָ��II
//
//����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i ƪ���ı����õĴ�����citations �Ѿ����� �������� ��
// ���㲢���ظ��о��ߵ� h ָ����
//
//h ָ���Ķ��壺h ���������ô�������high citations����
// һ��������Ա�� h ָ����ָ���������� ��n ƪ�����У����� �� h ƪ���ķֱ����������� h �Ρ�
//
//������Ʋ�ʵ�ֶ���ʱ�临�Ӷȵ��㷨��������⡣
//
//ʾ�� 1��
//
//���룺citations = [0, 1, 3, 5, 6]
//�����3
//���ͣ����������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 0, 1, 3, 5, 6 �Ρ�
//�����о�����3ƪ����ÿƪ ���� �������� 3 �Σ�������ƪ����ÿƪ������ ������ 3 �Σ�
//�������� h ָ���� 3 ��
//
//ʾ�� 2��
//
//���룺citations = [1, 2, 100]
//�����2

int hIndex(int* citations, int n) {
	int left = 0;
	int rihgt = n - 1;
	int mid = left + (rihgt - left) >> 1;
	while (citations[mid] > (n - mid)) {
		mid--;
	}
	while (citations[mid] < (n - mid)) {
		mid++;
	}
	return n - mid;
}

int main(void) {
	int citations[] = { 0,1,3,5,6 };
	int citations2[] = { 1,2,100 };
	int citations3[] = { 1,2,100,102,103,104,105,106 };
	//printf("%d\n", hIndex(citations, 5));
	//printf("%d\n", hIndex(citations2, 3));
	printf("%d\n", hIndex(citations3, 8));

	return 0;
}