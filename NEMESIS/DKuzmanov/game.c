#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

//pTurn - variable that changes every turn and says who's the active player

int seedNotGiven = 1;

void AI(struct board_t *board, int pTurn) {
	int hasMana = 1;
	int CardToPlay = 0;
	while (hasMana) {
		int i;
		for (i = 1; i < 5; i++ ) {
			if (board -> Player[pTurn].Open_Spots_Hand[i] != 1) //Check if there is Card in the hand slot
				if (board->Player[pTurn].cards_in_hand.card_deck[i].cost < board -> Player[pTurn].cards_in_hand.card_deck[CardToPlay].cost) //Compares mana cost of the current card vs selected one
					CardToPlay = i;
		}
		//Look for empty lanes to put the card in.
		for (i = 0; i < 5; i ++) 
			if (board -> Card_Positions[i][pTurn] == -1) {
					i = play_card(board, pTurn, CardToPlay,i);
					if (i == 2) hasMana = 0;
					break;
			}

	}
}

//Card generator 
struct card_t GenerateCard() {
	if (seedNotGiven) {
		srand(time(NULL));
		seedNotGiven = 0;
	}
	struct card_t GeneratedCard;
	
	int damage = rand()%10+1;
	GeneratedCard.damage = damage;

	int health = rand()%12+1;
	float dec = health/1.8;
	if (dec > damage) health = damage * 1.8; 
	GeneratedCard.health = health;
	
	int manacost = rand()%((damage+health)/2)+1;
	if (manacost > 10) manacost = 10;
	GeneratedCard.cost = manacost;

	return GeneratedCard;
}

struct deck_t GenerateMultipleCards(int NumberOfCards) {
	int i = 0;
	struct deck_t deck;
	deck.top = 0;
	while (i < NumberOfCards) {
		push_card(GenerateCard(),&deck);
		i++;
	}
	return deck;
}

int WriteGeneratedDeckToFile(struct deck_t *deck,char *filename) {
	FILE *fp;
	int prevSize = deck -> top;
	struct card_t CardToWrite;
	fp = fopen(filename, "w");
	if (fp == NULL) return 0; 
	while( deck->top != 0 ) {
		
		draw_card(deck,&CardToWrite);
		fprintf(fp,"NEMA IME,%d,%d,%d,\n",CardToWrite.cost,CardToWrite.damage,CardToWrite.health);

	}
	deck -> top = prevSize;
	fclose(fp);
	return 1;
}



int main() {
	struct board_t board;
	int winner = 0;
	int pTurn = 0;
	int pCard = 0;
	int mLane = 0;
	struct card_t generatedCard;
	struct deck_t generatedDeck = GenerateMultipleCards(30);
	WriteGeneratedDeckToFile(&generatedDeck,"teste.csv");
	generatedCard = GenerateCard();
	print_card(generatedCard,1);
	// INIT STUFF HERE !
	if (!init_board(&board)) {
		printf("Error! File Not Found!\n");
		return -1;
	}
	// =================
	winner = 0;
	while (winner == 0) {
		pCard = 0;
		board.Player[pTurn].turn++;
		turn_begin(&board.Player[pTurn]);
		//Printing Board!
		PrintBoard(board);
		//==================
		if (pTurn == 0) {
			while (pCard != 6) {
				printf("Choose card:");
				scanf("%d", &pCard);
				if (pCard != 6 && board.Player[pTurn].Open_Spots_Hand[pCard-1] != 1) {
					printf("Choose lane:");
					scanf("%d", &mLane);
					int result = play_card(&board, pTurn, pCard-1, mLane-1);
						PrintBoard(board);
				}
			}
		}
		else AI(&board, pTurn);
		turn_end (&board,pTurn);
		if (board.Player[pTurn].health <= 0) {				
			winner = 1-pTurn;		
			break;	
		}		
		pTurn = 1-pTurn;				
	}
	printf("\nWinner is Player: %d\n",winner+1);
	
	return 0;
}
