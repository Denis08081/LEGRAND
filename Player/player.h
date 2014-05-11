#ifndef Player
#define Player

#include "deck.h"
#include "card.h"
#include "manapool.h"

#define maxHP 30

struct player_t {
	int hp;
	char *name;
	struct deck_t deck;
	struct deck_t hand;
	struct manapool_t pool;
} player;

void init_player(struct player_t *player);
int change_hp(struct player_t *player, int hp);
int put_card(struct player_t *player, int card, struct card_t *return_card); 
struct card_t play_card_from_hard (struct player_t *player, int card);
void turn_begin(struct player_t *player);

#endif
