#ifndef Board
#define Board

#include "card.h"
#include "deck.h"
#include "player.h"

#define b_count 50

struct board_t {
	struct card_t position [2][5];
	struct player_t pl [2];
};


void init_board(struct board_t *board);
void print_border(char ch);
void print_field(struct board_t board, int side);
void print_board(struct board_t board);
int position_test(struct board_t board, int side, int coll);
int play_card(struct board_t *board, struct card_t card, int side);
void turn_end(struct board_t *board, int side);
int who_wins(struct board_t board);
int load_deck(struct board_t *board, int side, char *filename);
void game_begin(struct board_t *board, int *side);

#endif
