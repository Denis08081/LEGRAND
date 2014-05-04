#ifndef Deck
#define Deck

#include "card.h"

#define maxC 30

struct deck_t {
	int top;
	struct card_t card[maxC];
} deck;

void init_deck(struct deck_t *deck);
int push_card(struct card_t card_to_push, struct deck_t *player_deck);
int draw_card(struct deck_t *player_deck, struct card_t *card);
int look_card(struct deck_t *player_deck, struct card_t *card);

#endif


