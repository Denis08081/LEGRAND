#ifndef CARD
#define CARD

struct card_t {
	char name[25];
	int health;
	int damage;
	int cost;
};

int card_attack(struct card_t *attacker, struct card_t *defender);
#endif
