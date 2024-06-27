#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))
//请实现选择排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void selection_sort(int arr[], int n);
void selection_sort(int arr[], int n) {
	int min = 0;
	int temp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i-1];
		arr[i-1] = temp;
		min = i;
	}
}
//时间复杂度O（n²），空间复杂度O（1），不稳定

void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 1,7,2,3,5,9 };
	selection_sort(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}