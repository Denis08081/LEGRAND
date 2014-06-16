#include "print.h"

void print_card (struct card_t card, int i) {
	if(card.cost < 0) card.cost = 0;
	if (i == 1)
	printf("%d|%d (%d)|", card.health, card.damage, card.cost);
	else printf(" %d|%d  #", card.health, card.damage);
}

void print_border (char c) {
	int i;
	printf("\n");
	for (i = 0; i <= 65; i++) {
		printf("%c", c);
	}
	printf("\n");
}

void print_sharp1 (char c) {
	int i;
	printf("\n");
	for (i = 0; i <= 65; i++) {
		printf("%c", c);
	}
	printf("\n#");
}

void print_sharp2 (char c) {
	int i;
	printf("\n");
	for (i = 0; i <= 65; i++) {
		printf("%c", c);
	}
	printf("\n|");
}
