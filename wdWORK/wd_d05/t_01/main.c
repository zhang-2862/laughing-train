#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//��д����ģ�������ӵ���Ϸ���������ӣ���ÿ����Ϸ�Ĺ������£�
//
//��һ������ʱ���� ������֮��Ϊ 7 �� 11 ���ʤ���������֮��Ϊ2��3��12����ܣ���������µĵ���֮�ͳ�Ϊ��Ŀ�ꡱ����Ϸ�������ں�����Ͷ���У��������ٴ�������Ŀ�ꡱ�������ʤ������7����ܣ�������������ԣ���Ϸ�������С�
//
//ÿ����Ϸ����ʱ������ѯ���û��Ƿ�����һ�Σ������ ������Ļش��� y �� Y ���������ʾʤ�ܵĴ���Ȼ����ֹ��(��չ�⣬��Ҫ��ÿ��ͬѧ�ش�)
//
//You rolled : 8
//Your point is 8
//You rolled : 3
//You rolled : 10
//You rolled : 8
//You win!
//
//Play again ? y
//
//You rolled : 6
//Your point is 6
//You rolled : 5
//You rolled : 12
//You rolled : 3
//You rolled : 7
//You lose!
//
//Play again ? y
//
//You rolled : 11
//You win!
//
//Play again ? n
//
//Wins : 2 Losses : 1

int get_dice_points() {
	return 2 + rand() % 10;
}

bool play_game() {
	while (1) {
		int points = get_dice_points();
		printf("You rolled : %d\n", points);
		if (points == 7 || points == 11) {
			return true;
		}
		else if (points == 2 || points == 3 || points == 12) {
			return false;
		}
		else {
			printf("your point is %d\n", points);
		}
	}
}

int main(void) {
	srand((unsigned)time(NULL));

	//��ʤ��ʧ�ܵĴ���
	int wins=0;
	int losses=0;
	
	char ctrl = '0';

	do{
		play_game() ? wins++ : losses++;
		if (play_game()) {
			printf("You win!\n\n");
		}
		else {
			printf("You lose!\n\n");
		}
		printf("Play again ? ");
		scanf(" %c", &ctrl);
		printf("\n");
		if (ctrl != 'y' && ctrl != 'Y') {
			break;
		}
	} while (1);

	printf("Wins : %d Loses : %d", wins, losses);

	return 0;
}