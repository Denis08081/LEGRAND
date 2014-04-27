#include "card.h"
#include <stdio.h>

int attack (struct card_t *attacker, struct card_t *defender) {

	attacker -> health -= defender -> attack;
	defender -> health -= attacker -> attack;

	if (attacker -> health == 0 && defender -> health == 0) {
		return 0;
	} else if (attacker -> health > 0) {
			return 1;
		} else if (defender -> health > 0) {
			return 2;
			}
			else {
				return 3;
			}
}

void print_card (struct card_t card) {
	printf("%s[h = %d, a = %d, c = %d]", card.name, card.health, card.attack, card.cost);
}
