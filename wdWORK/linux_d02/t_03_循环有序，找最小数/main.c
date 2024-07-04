#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//假定一个数组有 n 个元素，这 n 个元素各不相同，并且循环有序，请找出最小的那个元素。
//
//int findMin(int arr[], int n);
//
//示例1：
//输入：[3, 4, 5, 1, 2]
//输出：1
//
//示例2：
//输入：[4, 5, 6, 7, 0, 1, 2]
//输出：0

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