#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void split_time(long total_sec, int* hour, int* minute, int* second) {
	*second = total_sec % 60;
	*minute = total_sec / 60 % 60;
	*hour = total_sec / 3600 % 24;
}

int main(void) {
	int hour;
	int minute;
	int second;

	int* phour = &hour;
	int* pminute = &minute;
	int* psecond = &second;

	split_time(6400L, phour, pminute, psecond);
	
	printf("%.2ld : %.2ld £º%.2ld", hour, minute, second);

	return 0;
}