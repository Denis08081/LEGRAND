#ifndef MANAPOOL
#define MANAPOOL

#include "card.h"
#include "deck.h"

#define MAXMANA 10

struct manapool_t {
	int mana;
	int max_mana;
};

//Checks if you have enough mana to put the card
int can_put_card (struct card_t card_to_put, struct manapool_t pool);
//Makes needed mana changes
int use_card (struct card_t card, struct manapool_t *pool);
//Additional algorithm for mana changes
int change_mana (struct manapool_t *manapool, int change);

#endif
