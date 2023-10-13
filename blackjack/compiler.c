#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#define SESSIONS 100

void start();

int main(void)
{
	start();
	Game game = createGame();
	printDeck(game.deck);

	free(game.deck.cards); // Is also run when the program is terminated so in this case it dosent make a difference
	return 0;
}

void start()
{
	srand(time(NULL));
}

