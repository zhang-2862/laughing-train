#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//请实现下列二分查找的变种：
//
//// 查找最后一个与 key 相等的元素
//int binary_search1(int arr[], int n, int key);
//// 查找最后一个小于等于 key 值的元素
//int binary_search2(int arr[], int n, int key);
// 
int binary_search1(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid = 0;//初始化为0
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (arr[mid] < key+1) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}//每一轮循环结束后一定有left的左边元素均小于key+1,
	 //right的右边元素均大于等于key+1
	if (arr[right] == key) {
		return right;
	} else {
		return -1;//表示未找到与key相等的元素
	}

}

int binary_search2(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid = 0;//初始化为0
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (arr[mid] < key + 1) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}//每一轮循环结束后一定有left的左边元素均小于key+1,
	 //right的右边元素均大于等于key+1
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