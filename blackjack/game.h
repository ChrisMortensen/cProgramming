
typedef struct
{
	Hand playerHand;
	Hand dealerHand;
	Deck deck;
} Game;

Game createGame (){
	Game game;
	game.deck = createDeck();
	shuffleDeck(&game.deck);
	drawCard(2, &game.deck, &game.playerHand);
	drawCard(1, &game.deck, &game.dealerHand);
	return game;
}


void drawCard (int amount, Deck *deck, Hand *hand){
	for (int i = 0; i < amount; i++)
	{
		Card card = deck->cards[0];
		hand->cards = (Card *)realloc(hand->cards, (hand->size + 1) * sizeof(Card));
		hand->cards[hand->size].suit = card.suit;
		hand->size++;
	}
	
}
