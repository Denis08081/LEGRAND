#ifndef Deck
#define Deck
#include "card.h"
#define deckS 30

struct deck_t {

	int cards;
	struct card_t card[deckS];
};

int push_card (struct card_t card_to_push, struct deck_t *player_deck);
int draw_card (struct deck_t *player_deck, struct card_t *card);
int look_card (struct deck_t *player_deck, struct card_t card);

#endif


