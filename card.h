#ifndef Card
#define Card

#define CN 25

struct card_t {
	char name[CN];
	int health;
	int attack;
	int cost;
};

int attack (struct card_t *attacker, struct card_t *defender);

#endif
