#define SESSIONS 100

typedef struct
{
	Hand playerHand;
	Hand dealerHand;
	Deck deck;
} Game;

void drawCard (Deck *deck, Hand *hand){
	Card card = deck->cards[0];
	hand->cards = (Card *)realloc(hand->cards, (hand->size + 1) * sizeof(Card));
	hand->cards[hand->size].suit = card.suit;
	hand->size++;
}
