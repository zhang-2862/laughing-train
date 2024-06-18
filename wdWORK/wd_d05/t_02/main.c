#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//德州扑克：写一个程序循环读取 5 张手牌(输入 0 结束程序)，然后把手中的牌分为下面某一类：
//1.同花顺 2.四张 3.葫芦(3 + 2) 4. 同花 5. 顺子 6.三张 7.两对 8. 一对 9.高牌

//同花 顺子 四张 三张 两对 一对，由此确定6位状态位，

//同花顺即 0b 110000  short型 值为48  0x30
//同花  即 0b 100000		  值为32  0x20
//顺子  即 0b 010000		  值为16  0x10
//四张  即 0b 001100		  值为12  0xC
//葫芦  即 0b 000101          值为5   0x5
//三张  即 0b 000100		  值为4   0x4
//两对  即 0b 000011	      值为3   0x3
//一对  即 0b 000001		  值为1   0x1
//高牌  即 0b 000000		  值为0   0x0

const char suits[4] = { 's','h','c','d' };//花色
const char cards[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };//牌面

static int card_state = 0;

bool is_suit_legal(char suit) {
	for (int i = 0; i < 4; i++)
	{
		if (suit == suits[i]) {
			return true;
		}
	}
	return false;
}

bool is_card_legal(char card) {
	for (int i = 0; i < 13; i++)
	{
		if (card == cards[i]) {
			return true;
		}
	}
	return false;
}

//用来确定牌面下标
int card_num(char card) {
	switch (card)
	{
	case '2':
		return 0;
	case '3':
		return 1;
	case '4':
		return 2;
	case '5':
		return 3;
	case '6':
		return 4;
	case '7':
		return 5;
	case '8':
		return 6;
	case '9':
		return 7;
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11;
	case 'A':
		return 12;
	default:
		return -1;
	}
}

//用来确定花色下标
int suit_num(char card) {
	switch (card)
	{
	case 's':
		return 0;
	case 'h':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	default:
		return -1;
	}
}

//是否为顺子
void straight(int card_count[]) {
	for (int i = 0; i <= 8; i++)
	{
		if (card_count[i] == 1 
			&& card_count[i + 1] == 1 
			&& card_count[i + 2] == 1
			&& card_count[i + 3] == 1
			&& card_count[i + 4] == 1
			) {
			card_state = card_state | 0x10;
		}
	}
}

//是否为同花
void flush(int suit_count[]) {
	for (int i = 0; i < 4; i++) {
		if (suit_count[i] > 4) {
			card_state = card_state | 0x20;
		}
	}
}

//判断同牌面有几张 另外判断是否有两对
void num_of_card(int card_count[]) {

	bool card_difference[13] = { false };//标记是否在另一对牌中出现过
	int pair_cnt = 0;//记录出现的对牌数

	for (int i = 0; i < 13; i++) {
		if (card_count[i] >= 4) {//四张
			card_state = card_state | 0xC;
			return;
		}
		if (card_count[i] == 3) {//三张
			card_state = card_state | 0x4;
			continue;
		}
		if (card_count[i] == 2) {//一对
			if (!card_difference[i]) {
				pair_cnt++;
			}
			card_difference[i] = true;
			card_state = card_state | 0x1;
		}
	}
	if (pair_cnt == 2) {
		card_state = card_state | 0x3;
	}
}

//打印牌型函数
void print_card_pattern() {
	switch (card_state)
	{
	case 48:
		printf("Straight Flush\n\n");
		break;
	case 12:
		printf("Four of a Kind\n\n");
		break;
	case 5:
		printf("Fullhouse\n\n");
		break;
	case 32:
		printf("Flush\n\n");
		break;
	case 16:
		printf("Straight\n\n");
		break;
	case 4:
		printf("Three of a Kind\n\n");
		break;
	case 3:
		printf("Two Pairs\n\n");
		break;
	case 1:
		printf("One Pairs\n\n");
		break;
	default:
		printf("High card\n\n");
		break;
	}
}

bool play_taxas_poker() {

	//用来记录对应花色牌号数量
	int suit_count[4] = { 0 };
	int card_count[13] = { 0 };

	//确定某张牌是否存在
	bool pokers_flag[4][13] = { false };

	//初始化
	
	char suit;
	char card;
	int cards_cnt = 0;

	while (true)
	{
		
		printf("Enter a card: ");
		scanf(" %c %c", &card, &suit);
		if (card == '0') {
			return true;
		}

		if (!is_suit_legal(suit)) {
			printf("Bad card; ignored.\n");
			continue;
		}
		if (!is_card_legal(card)) {
			printf("Bad card; ignored.\n");
			continue;
		}
		
		int suit_subscript = suit_num(suit);
		int card_subscript = card_num(card);
		if (pokers_flag[suit_subscript][card_subscript] == true) {
			printf("Duplicate card; ignored.\n");
			continue;
		}

		//牌面计数器自增
		pokers_flag[suit_subscript][card_subscript] = true;
		suit_count[suit_subscript]++;
		card_count[card_subscript]++;
		cards_cnt++;

		//读满五张牌后结束循环,并重置相关信息
		if (cards_cnt >= 5) {
			
			//计算牌型
			flush(suit_count);
			straight(card_count);
			num_of_card(card_count);

			//输出牌型
			print_card_pattern();
			
			cards_cnt = 0;
			card_state = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					suit_count[i] = 0;
					card_count[j] = 0;
					pokers_flag[i][j] = false;
				}
			}
		}

	}
}


int main(void) {
	while (true) {
		if (play_taxas_poker()) {
			break;
		}
	}
	return 0;
}