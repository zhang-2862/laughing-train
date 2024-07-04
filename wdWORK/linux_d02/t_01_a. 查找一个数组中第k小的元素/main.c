#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//a.查找一个数组中第k小的元素(思考: 能否将时间复杂度降低到O(n)呢)
//
//int find_kth_minimum(int arr[], int n, int k);
//

int find_kth_minimum(int arr[], int n, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = n-1; j >=i+1; j--) {
			if (arr[j] < arr[j - 1]) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			}
		}
	}
	return arr[k - 1];
}


int main(void) {
	int arr[] = { 7,9,4,2,3,5,1,0 };
	int k;
	scanf("%d", &k);
	int res=find_kth_minimum(arr, SIZE(arr), k);
	printf("The KTH smallest element is %d.\n", res);
	return 0;
}