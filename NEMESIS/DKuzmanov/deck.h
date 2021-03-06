#ifndef DECK
#define DECK

#define deck_size 30

#include "card.h"

struct deck_t {
	int top;
	struct card_t card_deck[deck_size];
};

int push_card (struct card_t card_to_push, struct deck_t *player_deck);
int draw_card (struct deck_t *player_deck, struct card_t *card);
int look_card (struct deck_t *player_deck, struct card_t *card);

#endif



