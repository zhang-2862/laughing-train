#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ٶ�һ�������� n ��Ԫ�أ��� n ��Ԫ�ظ�����ͬ������ѭ���������ҳ���С���Ǹ�Ԫ�ء�
//
//int findMin(int arr[], int n);
//
//ʾ��1��
//���룺[3, 4, 5, 1, 2]
//�����1
//
//ʾ��2��
//���룺[4, 5, 6, 7, 0, 1, 2]
//�����0

int findMin(int arr[], int n) {
	int left = 0;
	int right = n - 1;
	int mid = left + (right - left) >> 1;
	while (arr[mid] < arr[mid + 1]) {
		mid=(mid+1)%n;
	}
	return arr[++mid];
}

int main(void) {
	int arr[] = { 4, 5, 6, 7, 0, 1, 2 };
	int arr2[] = { 3, 4, 5, 1, 2 };
	printf("%d\n", findMin(arr, 7));

	return 0;
}