#ifndef Manapool
#define Manapool

#include "card.h"

struct manapool_t {
	int mana;
	int maxM;
};


void init_manapool(struct manapool_t *pool);

int use_mana(struct manapool_t *pool, int loss);

void get_mana(struct manapool_t *pool, int income);

int can_put_card(struct card_t card_to_put, struct manapool_t pool);

#endif
