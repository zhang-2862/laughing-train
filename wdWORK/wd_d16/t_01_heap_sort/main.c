#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(arr,i,j){  \
	int temp = arr[i];  \
	arr[i] = arr[j];    \
	arr[j] =temp;       \
}
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//请实现堆排序，并分析它的时间复杂度，空间复杂度和稳定性
//
//void heap_sort(int arr[], int n);




void heapify(int arr[], int len, int root_idx) {
	for (;;) {
		int left = (root_idx << 1) + 1;
		int right = (root_idx << 1) + 2;
		int max_idx = root_idx;
		if (right < len && arr[right] > arr[max_idx]) {
			max_idx = right;
		}
		if (left < len && arr[left] > arr[max_idx]) {
			max_idx = left;
		}
		if (max_idx == root_idx) {
			break;
		}
		SWAP(arr, max_idx, root_idx);
		root_idx = max_idx;
	}
}


void build_heap(int arr[], int len) {
	//从最后一个非叶子结点开始调整
	for (int i = len - 2 >> 1; i >= 0; i--) {
		heapify(arr, len, i);
	}
}

void heap_sort(int arr[], int n) {
	//先建立一个大根堆
	build_heap(arr, n);
	int len = n;
	//无序区长度初始为n
	while (len) {
		//将堆顶元素与当前堆中的最后一个元素调换
		SWAP(arr, 0, len - 1);
		len--;
		//重新调整为大根堆
		heapify(arr, len,0);
	}
	printf("\n");
}//时间复杂度为 O（nlogn） 空间复杂度为 O（1） 不稳定

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void) {
	int arr[] = { 0,9,4,2,3,4,7,1 };
	heap_sort(arr, SIZE(arr));
	print_arr(arr, SIZE(arr));

	return 0;
}