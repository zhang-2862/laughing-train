#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

//写一个随机发牌的程序。用户指定发几张牌，程序打印手牌。程序的会话如下：
//
//Enter number of cards in hand : 5
//Your hand : 9c 7d 3c 5d kd



int main(void) {

	srand((unsigned)time(NULL));

	const char cards[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
	const char card_suit[4] = { 'd','h','c','s' };//d方块、h红心、c梅花、s黑桃

	bool is_in_hand[4][13] = { false };

	int n;
	printf("Enter number of cards in hand : ");
	scanf("%d", &n);
	printf("Your hand : ");

	for (int num = 0; num < n; num++)
	{
		int i = rand() % 4;
		int j = rand() % 13;
		if (!is_in_hand[i][j]) {
			printf("%c%c ", cards[j], card_suit[i]);
		}
	}

	printf("\n");



	return 0;
}