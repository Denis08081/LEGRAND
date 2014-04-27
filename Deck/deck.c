#include "deck.h"
#include <stdio.h>


void init_deck ( struct deck_t *deck ) {
	int i = 0;
	for(i = 0; i <= maxC; i++;) {
		deck->top = 1;
	}
}


int push_card ( struct card_t card_to_push, struct deck_t *player_deck ) {
	if (player_deck->top >= maxC) {
		return -1;
	}

	player_deck->card_to_push[player_deck->top++] = card_to_push;
	return 0;
}

int draw_card (struct deck_t *player_deck, struct card_t *card) {
	int result = look_card(player_deck, card);
	if(result == 0) {
		player_deck->top--;
	}
	return result;
}

int look_card (struct deck_t *player_deck, struct card_t *card) {
	if (player_deck->top <= 0) {
		return -1;
	}
	
	*card = player_deck->cards[player_deck->top - 1];
	return 0;
}


