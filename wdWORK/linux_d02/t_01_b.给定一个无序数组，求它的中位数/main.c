#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//b.����һ���������飬��������λ��
//
//int find_median(int arr[], int n);
//
//���룺[3, 1, 2]
//�����2
//
//����[4, 1, 3, 2]
//�����2

int find(int arr[], int n, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	return arr[k - 1];
}


int find_median(int arr[], int n) {
	find(arr, n, (n >> 1));
}

int main(void) {
    int arr[] = { 5,4,1,3,6,9 };
    printf("The median is %d\n", find_median(arr, 6));

    return 0;
}