#include "manapool.h"

int can_put_card(struct card_t card_to_put, struct manapool_t pool){
	
	if(card_to_put.mana <= pool.mana) 
		return 1;
	return 0;
}

int MP_use_card(struct card_t card, struct manapool_t *pool) {
	pool-> mana -= card.mana;
}

