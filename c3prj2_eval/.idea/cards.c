#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
	assert(c.value >= 2 && c.value <= VALUE_ACE);
	assert(c.suit >= 0 && c.suit <= 3);
}

const char * ranking_to_string(hand_ranking_t r) {
	if(r == STRAIGHT_FLUSH)
			return "STRAIGHT_FLUSH";
	else if(r == FOUR_OF_A_KIND)
			return "FOUR_OF_A_KIND";
	else if(r == FULL_HOUSE)
			return "FULL_HOUSE";
	else if(r == THREE_OF_A_KIND)
			return "THREE_OF_A_KIND";
	else if(r == TWO_PAIR)
			return "TWO_PAIR";
	else if(r == PAIR)
			return "PAIR";
	else if(r == NOTHING)
			return "NOTHING";
	else
			return '\0';
}

char value_letter(card_t c) {
	char str;
	if(c.value >= 2 && c.value <= 9){
			str = c.value + '0';
	}
	else if(c.value == 10)
			str = '0';
	else if(c.value == VALUE_ACE)
			str = 'A';
	else if(c.value == VALUE_KING)
			str = 'K';
	else if(c.value == VALUE_QUEEN)
			str = 'Q';
	else if(c.value == VALUE_JACK)
			str ='J';
	else
			str = '?';
	return str;
}


char suit_letter(card_t c) {
		char x;
		if(c.suit == 0)
				x = 's';
		else if(c.suit == 1)
				x = 'h';
		else if(c.suit == 2)
				x = 'd';
		else if(c.suit == 3)
				x = 'c';
		else
				x = '?';
		return x;
}

void print_card(card_t c) {
		printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  	card_t temp;
	printf("%c %c\n",value_let, suit_let);
	if(value_let >= '2' && value_let <= '9')
			temp.value = (int)value_let - '0';
	else if(value_let == '0')
			temp.value = 10;
	else if(value_let == 'A')
			temp.value = VALUE_ACE;
	else if(value_let == 'K')
			temp.value = VALUE_KING;
	else if(value_let == 'Q')
			temp.value = VALUE_QUEEN;
	else if(value_let == 'J')
			temp.value = VALUE_JACK;
	else
		assert_card_valid(temp);

	if(suit_let == 's')
			temp.suit = 0;
	else if(suit_let == 'h')
			temp.suit = 1;
	else if(suit_let == 'd')
			temp.suit = 2;
	else if(suit_let == 'c')
			temp.suit = 3;
	else
		assert_card_valid(temp);
	return temp;
}

card_t card_from_num(unsigned c) {
	card_t temp;
		temp.value = (c / 4) + 2;
		temp.suit = c % 4;
		return temp;
}
