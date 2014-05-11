#include <stdio.h>

#include "card.h"
#include "deck.h"
#include "manapool.h"
#include "player.h"

void init_player(struct player_t *player) {
	player->name = NULL;
	init_deck(&player->deck);
	init_deck(&player->hand);
	init_manapool(&player->pool);
	player->hp = 0;
}

void change_hp(struct player_t *player, int hp) {
	if(hp > maxHP) {
		player->hp = maxHP;
	} else {
		player->hp += hp;
		if(player->hp < 0) player->hp = 0;
	}
}

int put_card(struct player_t *player, int card, struct card_t *return_card) {
	if(player->hand.top == 0) return -1;
	*return_card = player->hand.card[card];
	player->hand.top--;
	return 0;
}

struct card_t play_card_from_hand(struct player_t *player, int card) {
	int i;	
	struct card_t played_card;
	if(put_card(player, card, &played_card) == -1) {
		for(i = card + 1; i <= player->hand.top; i++) {
			player->hand.card[i - 1] = player->hand.card[i];
		}
	}
		return played_card;
}

void turn_begin(struct player_t *player) {
	struct card_t drawn_card;
	if(draw_card(&player->deck, &drawn_card) == -1) player->hand.card[player->hand.top++] = drawn_card;	
}


