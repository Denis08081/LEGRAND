#include <stdio.h>
#include "player.h"

int main() {
	struct player_t player;
	struct card_t betty = {"The Betty Cat", 5, 4, 7};
	struct card_t hamster = {"The Hamster Maya", 3, 10, 6};
	struct card_t card;

	init_player(&player);
	player.deck.top = 30;
	player.deck.card[29] = betty;
	player.deck.card[27] = betty;
	turn_begin(&player);
	turn_begin(&player);
	turn_begin(&player);
	turn_begin(&player);
	card = play_card_from_hand(&player, 1);
	printf("\nCARD PLAYED: ");
	print_card(card);
	change_hp(&player, 15);
	printf("player:\n");
	

return 0;
}
