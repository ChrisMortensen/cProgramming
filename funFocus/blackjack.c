#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SHUFFLES 100

typedef enum
{
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
} Rank;

typedef enum
{
	heart,
	spade,
	club,
	diamond
} Suit;

typedef struct
{
	Rank rank;
	Suit suit;
} Card;

typedef struct
{
	Card *cards;
	int size;
} Deck;

Deck createDeck();
void shuffleDeck(Deck *);
void addCard(Deck *deck, Card card);
void printDeck(Deck);
void start();
void removeCard(Deck *deck, Card cardToRemove);

int main(void)
{
	start();
	Deck deck = createDeck(deck);
	shuffleDeck(&deck);
	Card newCard;
	newCard.suit = heart;
	newCard.rank = four;
	addCard(&deck, newCard);
	removeCard(&deck, newCard); // Removes the first four of hearts in the deck
	printDeck(deck);

	free(deck.cards); // Is also run when the program is terminated so in this case it dosent make a difference
	return 0;
}

void start()
{
	srand(time(NULL));
}

Deck createDeck()
{
	Deck deck;
	deck.cards = (Card *)malloc(52 * sizeof(Card));
	deck.size = 0;
	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 2; rank <= 14; rank++)
		{
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

void removeCard(Deck *deck, Card cardToRemove)
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
