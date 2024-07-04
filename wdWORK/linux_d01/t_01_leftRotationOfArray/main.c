#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(arr,i,j) {	\
	int temp =arr[i];	\
	arr[i]=arr[j];		\
	arr[j]=temp;		\
}
//给定一个数组，将数组向左旋转k位.
//void rotateLeft(int arr[], int n, int k);
//
//输入：[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 0
//输出：[0, 1, 2, 3, 4, 5, 6, 7, 8]
//
//输入：[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 3
//输出：[3, 4, 5, 6, 7, 8, 0, 1, 2]
//
//输入：[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 10
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 0]

void reverse_arr(int arr[], int left, int right) {
	while (left<right) {
		SWAP(arr, left, right);
		left++;
		right--;
	}
}

void rotateLeft(int arr[], int n, int k) {
	int left = 0;
	int right = n - 1;
	k = k % n;
	reverse_arr(arr, left, right);
	reverse_arr(arr, right - k+1, right);
	reverse_arr(arr, left, right-k);
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int k;

	printf("please input rotate num: \n");
	scanf("%d", &k);
	rotateLeft(arr, 9, k);
	print_arr(arr, 9);

	return 0;
}