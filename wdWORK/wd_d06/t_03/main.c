#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_tow_largest(int arr[], int n, int* largest, int* second_largest) {
	int max = 0;
	int bigest=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
			bigest = i;
		}
		*largest = max;
	}
	max = 0;
	for (int j = 0; j < n; j++)
	{
		if (j == bigest) {
			continue;
		}
		if (arr[j] > max ) {
			max = arr[j];
		}
	}
	*second_largest = max;
}

int main(void) {
	int largest = 0;
	int second_largest = 0;

	int* plargest = &largest;
	int* psecond_largest = &second_largest;

	int arr[10] = { 10,13,14,19,77,8,33,49,99,54 };
	
	find_tow_largest(arr, 10, plargest, psecond_largest);

	printf("largest number is %d.\nsecond largest number is %d.", largest, second_largest);

	return 0;
}