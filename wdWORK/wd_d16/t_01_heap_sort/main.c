#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(arr,i,j){  \
	int temp = arr[i];  \
	arr[i] = arr[j];    \
	arr[j] =temp;       \
}
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//��ʵ�ֶ����򣬲���������ʱ�临�Ӷȣ��ռ临�ӶȺ��ȶ���
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
	//�����һ����Ҷ�ӽ�㿪ʼ����
	for (int i = len - 2 >> 1; i >= 0; i--) {
		heapify(arr, len, i);
	}
}

void heap_sort(int arr[], int n) {
	//�Ƚ���һ�������
	build_heap(arr, n);
	int len = n;
	//���������ȳ�ʼΪn
	while (len) {
		//���Ѷ�Ԫ���뵱ǰ���е����һ��Ԫ�ص���
		SWAP(arr, 0, len - 1);
		len--;
		//���µ���Ϊ�����
		heapify(arr, len,0);
	}
	printf("\n");
}//ʱ�临�Ӷ�Ϊ O��nlogn�� �ռ临�Ӷ�Ϊ O��1�� ���ȶ�

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