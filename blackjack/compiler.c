#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"

void start();

int main(void)
{
	start();
	Deck deck = createDeck(deck);
	shuffleDeck(&deck);
	printDeck(deck);
	free(deck.cards); // Is also run when the program is terminated so in this case it dosent make a difference
	return 0;
}

void start()
{
	srand(time(NULL));
}

