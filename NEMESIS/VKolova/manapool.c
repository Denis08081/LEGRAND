#include "manapool.h"

int can_put_card (struct card_t card_to_put, struct manapool_t pool) {
	if(card_to_put.cost <= pool.mana) 
		return 1;
	return 0;

}

int use_card(struct card_t card, struct manapool_t *pool) {
	pool-> mana -= card.cost;
}

int change_mana(struct manapool_t *manapool,int change) {
	//Change can be negative and/or positive	
	manapool-> mana += change;
	if (manapool -> mana > MAXMANA)
		manapool -> mana = MAXMANA;
}
