#include "manapool.h"
#include "card.h"
#include <stdio.h>

void init_manapool(struct manapool_t *pool) {
	pool->mana = 1;
	pool->maxM = 1;
}

int use_mana(struct manapool_t *pool, int loss) {
    if(loss > pool->mana) return 0;
    pool->mana -= loss;
    return 1;
}

void gain_mana(struct manapool_t *pool, int income) {
    if(income > pool->maxM){
        pool->mana = pool->maxM;
    } else {
        pool->mana += income;
    }
}

int can_put_card(struct card_t card, struct manapool_t pool) {
    return card.cost > pool.mana ? -1 : 0;
}
