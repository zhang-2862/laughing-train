#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//x为数组名
//请实现插入排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void insertion_sort(int arr[], int n);

void insertion_sort(int arr[], int n) {
	int value = 0;//用来暂存要插入的元素
	for (int i = 1; i < n; i++) {
		value = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > value) {
			arr[j+1] = arr[j];
			j--;
		}//arr[j] <= value
		arr[j + 1] = value;
	}
}//时间复杂度 O（n²） 空间复杂度 O（1） 稳定

void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 1,7,2,3,5,9 };
	insertion_sort(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}