#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//x为数组名

//请实现冒泡排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void bubble_sort(int arr[], int n);

void bubble_sort(int arr[], int n) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		flag = false;
		for (int j = n-1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = true;
			}
		}
		if (flag == false) {
			return;
		}
	}
}

//  时间复杂度：O（n²） 空间复杂度：O（1） 稳定


void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 1,7,2,3,5,9 };
	bubble_sort(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}