#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//x为数组名

//给定一个排好序的数组，请设计一个算法将数组随机打乱。
//
//void shuffle(int arr[], int n);



void shuffle(int arr[], int n) {
	int idx = 0;
	for (int i = 0; i < n; i++) {
		//遍历元素并与数组内元素进行随机交换
		idx = rand() % n;
		int temp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = temp;
	}
}


void print_array(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	srand((unsigned)time(NULL));

	int arr[] = { 1,7,2,3,5,9 };
	print_array(arr, SIZE(arr));

	printf("after shuffle\n");

	shuffle(arr, SIZE(arr));
	print_array(arr, SIZE(arr));

	return 0;
}