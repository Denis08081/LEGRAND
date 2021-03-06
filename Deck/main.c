#include "deck.c"
#include "card.h"
#include <stdio.h>

int main() {

	struct card_t card_1 = {"Tower", 55, 50, 5};
	struct card_t card_2 = {"Windrunner", 5, 15, 5};
	struct card_t card_3 = {"The Beat", 78, 39, 6};


	struct deck_t myD;

	init_deck(&myD);
	push_card(card_1, &myD);
	push_card(card_2, &myD);
	push_card(card_3, &myD);

	struct card_t topC;

	if(draw_card(&myD, &topC) == 0) {
		print_card(topC);
	}

	if(draw_card(&myD, &topC) == 0) {
		struct card_t almostTopC;
		if(draw_card(&myD, &almostTopC) == 0) {
			printf("%d\n", attack(&topC, &almostTopC));
			print_card(almostTopC);
			print_card(topC);
		}

	}

	return 0;
}
