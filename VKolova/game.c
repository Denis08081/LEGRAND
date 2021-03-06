#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

int main() {
	struct card_t card[2];
	struct deck_t deck1;
	struct player_t Player1;
	struct board_t board;
	int winner = 0;
	//Who is first !
	srand (time(NULL));
	int pTurn = rand() % 2;
	// =============
	int pCard = 0;
	int mLane = 0;

	if (!init_board(&board)) {
		printf("Error. Deck not loaded!\n");
		return -1;
	}

	winner = 0;
	while(winner == 0) {
		pCard = 0;
		board.Player[pTurn].turn++;
		turn_begin(&board.Player[pTurn]);
		//Print Board Here !
		PrintBoard(board);
		//==================
		while (pCard != 6) {
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
		if (board.Player[pTurn].health <= 0) {				
			winner = 1-pTurn;
			break;
		}		
		pTurn = 1-pTurn;				
	}
	printf("\n\nWinner is Player: %d\n\n", winner+1);
	
	return 0;
}
