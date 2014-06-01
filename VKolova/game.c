#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main() {
	struct card_t card[2];
	struct deck_t deck1;
	struct player_t Player1;
	struct board_t board;
	int winner = 0;
	//AI !
	srand (time(NULL));
	int pTurn = rand() % 2;
	// ===
	int pCard = 0;
	int mLane = 0;
	// INIT STUFF HERE !
	if (!init_board(&board)) {
		printf("Error. Deck not loaded!\n");
		return -1;
	}
	// =================
	winner = 0;
	while(winner == 0) {
		pCard = 0;
		board.Player[pTurn].turn++;
		turn_begin(&board.Player[pTurn]);
		//Print Board Here !
		PrintBoard(board);
		//==================
		while (pCard != 6) {
			//MORE AI STUFF !
			/*if (board.Player[first_pl].turn >= board.Player[first_pl].turn && pTurn == 0) {
				int min;
				for(int i=0; i<5; i++) {
					if (board->Player[first_pl].cards_in_hand.card_deck[i].mana < board->Player[first_pl].manapool) {
						min = i;
						play_card(&board, pTurn, min-1, mLane-1);
						}
				}

			}*/
			// ==============
			printf("Choose card: ");
			scanf("%d", &pCard);
			if (pCard !=6 && board.Player[pTurn].Open_Spots_Hand[pCard-1] != 1) {
				printf("Choose lane: ");
				scanf("%d", &mLane);
				int result = play_card(&board, pTurn, pCard-1, mLane-1);
						PrintBoard(board);
			}		
			
		}
		turn_end(&board, pTurn);
		pTurn = 1 - pTurn;
		if (board.Player[pTurn].health <= 0) winner = pTurn+1;	
	}
	printf("\n\nWinner is Player: %d\n\n", winner);
	
	return 0;
}
