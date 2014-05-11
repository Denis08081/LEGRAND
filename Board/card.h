#ifndef Card
#define Card

#define CName 25

struct card_t {
	char name[CName];
	int health;
	int attack;
	int cost;
};

int attack (struct card_t *attacker, struct card_t *defender);

#endif
