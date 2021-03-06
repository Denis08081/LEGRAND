#include "manapool.c"
#include <stdio.h>

int main() {
	struct manapool_t myP;
	struct card_t card = {"Betty The Andry Cat", 9, 17, 5};

	init_manapool(&myP);
	printf("Start mana: %d / %d\n", myP.mana, myP.maxM);
	myP.maxM = 10;	

	gain_mana(&myP, 7);
	printf("Mana after gaining: %d / %d\n", myP.mana, myP.maxM);

	if(can_put_card(card, myP) == 0) {
		use_mana(&myP, card.cost);
		printf("Mana after putting a card: %d / %d\n", myP.mana, myP.maxM);
	
	} else {
		printf("You don't have enough mana\n");
		}



	if( can_put_card(card, myP) == 0) {
		use_mana(&myP, card.cost);
		printf("Mana after putting a second card: %d / %d\n", myP.mana, myP.maxM);
	} else {
			printf("You don't have enough mana\n");
		}

return 0;
}
