#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
	int sz = hand->n_cards;
	for(int i = 0;i < sz;i ++){
		print_card(*hand->cards[i]);
		printf(" ");
	}
}

int deck_contains(deck_t * d, card_t c) {
	int sz = d->n_cards;
	for(int i = 0;i < sz;i ++){
		if(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
			return 1;
	}
	return 0;
}

void shuffle(deck_t * d){
	int sz = d->n_cards;
	for(int i = 0;i < sz;i ++){
		int random = rand() % sz;
		card_t temp = *d->cards[i];
		*d->cards[i] = *d->cards[random];
		*d->cards[random] = temp;
	}
}

void assert_full_deck(deck_t * d) {
	int sz = d->n_cards;
	for(int i = 0;i < sz;i ++){
		assert(deck_contains(d, card_from_num(i)) == 1);
	}
}
