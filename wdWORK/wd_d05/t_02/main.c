#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//�����˿ˣ�дһ������ѭ����ȡ 5 ������(���� 0 ��������)��Ȼ������е��Ʒ�Ϊ����ĳһ�ࣺ
//1.ͬ��˳ 2.���� 3.��«(3 + 2) 4. ͬ�� 5. ˳�� 6.���� 7.���� 8. һ�� 9.����

//ͬ�� ˳�� ���� ���� ���� һ�ԣ��ɴ�ȷ��6λ״̬λ��

//ͬ��˳�� 0b 110000  short�� ֵΪ48  0x30
//ͬ��  �� 0b 100000		  ֵΪ32  0x20
//˳��  �� 0b 010000		  ֵΪ16  0x10
//����  �� 0b 001100		  ֵΪ12  0xC
//��«  �� 0b 000101          ֵΪ5   0x5
//����  �� 0b 000100		  ֵΪ4   0x4
//����  �� 0b 000011	      ֵΪ3   0x3
//һ��  �� 0b 000001		  ֵΪ1   0x1
//����  �� 0b 000000		  ֵΪ0   0x0

const char suits[4] = { 's','h','c','d' };//��ɫ
const char cards[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };//����

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

//����ȷ�������±�
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

//����ȷ����ɫ�±�
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

//�Ƿ�Ϊ˳��
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

//�Ƿ�Ϊͬ��
void flush(int suit_count[]) {
	for (int i = 0; i < 4; i++) {
		if (suit_count[i] > 4) {
			card_state = card_state | 0x20;
		}
	}
}

//�ж�ͬ�����м��� �����ж��Ƿ�������
void num_of_card(int card_count[]) {

	bool card_difference[13] = { false };//����Ƿ�����һ�����г��ֹ�
	int pair_cnt = 0;//��¼���ֵĶ�����

	for (int i = 0; i < 13; i++) {
		if (card_count[i] >= 4) {//����
			card_state = card_state | 0xC;
			return;
		}
		if (card_count[i] == 3) {//����
			card_state = card_state | 0x4;
			continue;
		}
		if (card_count[i] == 2) {//һ��
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

//��ӡ���ͺ���
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

	//������¼��Ӧ��ɫ�ƺ�����
	int suit_count[4] = { 0 };
	int card_count[13] = { 0 };

	//ȷ��ĳ�����Ƿ����
	bool pokers_flag[4][13] = { false };

	//��ʼ��
	
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

		//�������������
		pokers_flag[suit_subscript][card_subscript] = true;
		suit_count[suit_subscript]++;
		card_count[card_subscript]++;
		cards_cnt++;

		//���������ƺ����ѭ��,�����������Ϣ
		if (cards_cnt >= 5) {
			
			//��������
			flush(suit_count);
			straight(card_count);
			num_of_card(card_count);

			//�������
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