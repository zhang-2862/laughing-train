#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//xΪ������

//��ʵ�ֿ������򣬲���������ʱ�临�Ӷȣ��ռ临�ӶȺ��ȶ���
//
//void quick_sort(int arr[], int n);

//����
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
}//  ʱ�临�Ӷȣ� O��nlogn) �ռ临�Ӷ� O��logn�� ���ȶ�


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