#include <stdio.h>
#include "card.c"

int main() {
	struct card_t card_1 = {"Elite Tauren Chieftain", 5, 5, 5};
	struct card_t card_2 = {"Sylvanas Windrunner", 5, 5, 5};
	struct card_t card_3 = {"The Beast", 7, 9, 6};
	struct card_t card_4 = {"Wicked Knife", 1, 2, 2};
	struct card_t card_5 = {"Leeroy Jenkins", 6, 2, 4};

	printf("winner (Elite Tauren Chieftain vs Sylvanas Windrunner): %d\n", attack(&card_1, &card_2));
	printf("Elite Tauren Chieftain: %d | %d \n", card_1.attack, card_1.health);
	printf("Sylvanas Windrunner: %d | %d \n", card_2.attack, card_2.health);

	printf("\nwinner (The Beast vs Sylvanas Windrunner): %d\n", attack(&card_3, &card_2));
	printf("The Beast: %d | %d \n", card_3.attack, card_3.health);
	printf("Sylvanas Windrunner: %d | %d \n", card_2.attack, card_2.health);

	printf("\nwinner (Wicked Knife vs Leeroy Jenkins): %d\n", attack(&card_4, &card_5));	
	printf("Wicked Knife: %d | %d \n", card_4.attack, card_4.health);
	printf("Leeroy Jenkins: %d | %d \n", card_5.attack, card_5.health);

	printf("\nwinner (Sylvanas Windrunner vs Leeroy Jenkins): %d\n", attack(&card_2, &card_5));
	printf("Sylvanas Windrunner: %d | %d \n", card_2.attack, card_2.health);
	printf("Leeroy Jenkins: %d | %d \n", card_5.attack, card_5.health);

 
	return 0;
}
