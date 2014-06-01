#ifndef xCARD
#define xCARD

struct card_t {
	char name[25];
	int mana;
	int damage;
	int health;
	//PART OF SPECIAL CARDS !
	int s_attack;
	//END !
};

int card_attack(struct card_t *attacker, struct card_t *defender);
void print_card(struct card_t card, int i);

#endif
