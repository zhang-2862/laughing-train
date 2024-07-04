#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(arr,i,j) {	\
	int temp =arr[i];	\
	arr[i]=arr[j];		\
	arr[j]=temp;		\
}
//����һ�����飬������������תkλ.
//void rotateLeft(int arr[], int n, int k);
//
//���룺[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 0
//�����[0, 1, 2, 3, 4, 5, 6, 7, 8]
//
//���룺[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 3
//�����[3, 4, 5, 6, 7, 8, 0, 1, 2]
//
//���룺[0, 1, 2, 3, 4, 5, 6, 7, 8], k = 10
//�����[1, 2, 3, 4, 5, 6, 7, 8, 0]

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