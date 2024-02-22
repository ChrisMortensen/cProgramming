#ifndef DECK_H
#define DECK_H

#define SHUFFLES 100

typedef struct
{
	Card *cards;
	int size;
} Deck;

Deck createDeck()
{
	Deck deck;
	deck.cards = (Card *)malloc(52 * sizeof(Card));
	deck.size = 0;
	for (int suit = 0; suit < 4; suit++){
		for (int rank = 2; rank <= 14; rank++){
			if(rank == 14){
				deck.cards[deck.size].value = 11;
			} else if (rank>10){
				deck.cards[deck.size].value = 10;
			} else{
				deck.cards[deck.size].value = rank;
			}
			deck.cards[deck.size].rank = rank;
			deck.cards[deck.size].suit = suit;
			deck.size++;
		}
	}
	return deck;
}

void shuffleDeck(Deck *deck)
{
	for (int i = 0; i < SHUFFLES; i++)
	{
		int r1 = rand() % deck->size;
		int r2 = rand() % deck->size;
		Card tempCard = deck->cards[r1];
		deck->cards[r1] = deck->cards[r2];
		deck->cards[r2] = tempCard;
	}
}

void printDeck(Deck deck)
{
	for (int i = 0; i < deck.size; i++)
	{
		Card card = deck.cards[i];
		printf("Card %2d: Rank %2d, Suit %d\n", i + 1, card.rank, card.suit);
	}
}

void addCard(Deck *deck, Card card)
{
	deck->cards = (Card *)realloc(deck->cards, (deck->size + 1) * sizeof(Card));

	deck->cards[deck->size].suit = card.suit;
	deck->cards[deck->size].rank = card.rank;
	deck->size++;
}

void removeSpecificCard(Deck *deck, Card cardToRemove)
{
	int i = 0;
	int found = 0;
	while (i < deck->size && found == 0)
	{
		if (deck->cards[i].suit == cardToRemove.suit && deck->cards[i].rank == cardToRemove.rank)
		{
			for (int j = i; j < deck->size - 1; j++)
			{
				deck->cards[j] = deck->cards[j + 1];
			}
			deck->size--;
			deck->cards = (Card *)realloc(deck->cards, deck->size * sizeof(Card));
			found = 1;
		}
		else
		{
			i++;
		}
	}
}

void destroyDeck(Deck *deck) {
    if (deck->cards != NULL) {
        free(deck->cards);
        deck->cards = NULL;
        deck->size = 0;
    }
}

#endif