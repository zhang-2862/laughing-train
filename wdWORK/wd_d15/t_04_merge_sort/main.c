#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//x为数组名
//请实现归并排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void merge_sort(int arr[], int n);

void merge(int arr[], int left,int mid,int right) {
	int result[6] = { 0 };
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i<=mid && j<=right) {
		if (arr[i] <= arr[j]) {
			result[k++] = arr[i++];		
		}else {
			result[k++] = arr[j++];
		}
	}

    while (i <= mid) {
        result[k++] = arr[i++];
    }
	while (j <= right) {
		result[k++] = arr[j++];
	}
	//将排序结果赋值到原数组中
	for (int i = left; i <= right; i++) {
		arr[i] = result[i];
	}
}


void m_sort(int arr[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left >> 1);
		m_sort(arr, left, middle);
		m_sort(arr, middle + 1, right);
		merge(arr,left,middle,right);
	}
}


void merge_sort(int arr[], int n) {
	m_sort(arr,0,n-1);
	printf("\n");
}//时间复杂度 O（nlogn）空间复杂度（logn）稳定

void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 1,7,2,3,5,9 };
	merge_sort(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}