#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//x为数组名

//请实现快速排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void quick_sort(int arr[], int n);

//划分
int partition(int arr[],int low,int high) {
	int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= arr[low]) {
			high--;
        }
		arr[low] = arr[high];
		while (low < high && arr[low] <= arr[high]) {
			low++;
		}
		arr[high] = arr[low];
    }
	arr[low] = pivot;
}

void q_sort(int arr[], int left, int right) {
	if (left < right) {
		int pos = partition(arr, left, right);
		q_sort(arr, left, pos);
		q_sort(arr, pos + 1, right);
	}
}

void quick_sort(int arr[], int n) {
	int left = 0;
	int right = n - 1;
	q_sort(arr, 0, n - 1);
	printf("\n");
}//  时间复杂度： O（nlogn) 空间复杂度 O（logn） 不稳定


void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 1,7,2,3,5,9 };
	quick_sort(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}