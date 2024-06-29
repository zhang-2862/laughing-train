#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//��ʵ�����ж��ֲ��ҵı��֣�
//
//// �������һ���� key ��ȵ�Ԫ��
//int binary_search1(int arr[], int n, int key);
//// �������һ��С�ڵ��� key ֵ��Ԫ��
//int binary_search2(int arr[], int n, int key);
// 
int binary_search1(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid = 0;//��ʼ��Ϊ0
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (arr[mid] < key+1) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}//ÿһ��ѭ��������һ����left�����Ԫ�ؾ�С��key+1,
	 //right���ұ�Ԫ�ؾ����ڵ���key+1
	if (arr[right] == key) {
		return right;
	} else {
		return -1;//��ʾδ�ҵ���key��ȵ�Ԫ��
	}

}

int binary_search2(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid = 0;//��ʼ��Ϊ0
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (arr[mid] < key + 1) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}//ÿһ��ѭ��������һ����left�����Ԫ�ؾ�С��key+1,
	 //right���ұ�Ԫ�ؾ����ڵ���key+1
	return right;
}

int main(void) {
	int arr[] = { 1,4,7,9,9,9,14,25,27 };
	int res1 = binary_search1(arr, SIZE(arr), 8);

	int res2 = binary_search2(arr, SIZE(arr), 15);

	printf("the position of last equal key is %d.\n\n", res1);
	printf("the position of last less or equal key is %d.\n", res2);

	return 0;
}