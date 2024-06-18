#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//编写程序模拟掷骰子的游戏（两个骰子）。每局游戏的规则如下：
//
//第一次掷的时候，如 果点数之和为 7 或 11 则获胜；如果点数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，其他情况都忽略，游戏继续进行。
//
//每局游戏结束时，程序询问用户是否再玩一次，如果用 户输入的回答不是 y 或 Y ，程序会显示胜败的次数然后终止。(拓展题，不要求每个同学回答)
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

	//获胜与失败的次数
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