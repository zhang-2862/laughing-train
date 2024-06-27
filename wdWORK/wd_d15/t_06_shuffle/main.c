#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))//xΪ������

//����һ���ź�������飬�����һ���㷨������������ҡ�
//
//void shuffle(int arr[], int n);



void shuffle(int arr[], int n) {
	int idx = 0;
	for (int i = 0; i < n; i++) {
		//����Ԫ�ز���������Ԫ�ؽ����������
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