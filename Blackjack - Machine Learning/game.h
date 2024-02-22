#ifndef GAME_H
#define GAME_H

typedef struct
{
	Hand playerHand;
	Hand dealerHand;
	Deck deck;
	int bet;
} Game;

void drawCard (int, Deck *, Hand *);
void initializeHand(Hand *);

Game createGame (){
	Game game;
	game.bet = 0;
	game.deck = createDeck();
	initializeHand(&game.dealerHand);
	initializeHand(&game.playerHand);
	shuffleDeck(&game.deck);
	drawCard(2, &game.deck, &game.playerHand);
	drawCard(1, &game.deck, &game.dealerHand);
	return game;
}

void initializeHand(Hand* hand) {
    hand->cards = NULL;
    hand->size = 0;
    hand->soft = 0;
	hand->sum = 0;
}

void drawCard (int amount, Deck *deck, Hand *hand){
	for (int i = 0; i < amount; i++){
		Card card = deck->cards[0];
		if(card.value == 11){
			hand->soft++;
		}
		hand->cards = (Card *)realloc(hand->cards, (hand->size + 1) * sizeof(Card));
		hand->cards[hand->size] = card;
		hand->size++;
		hand->sum+=card.value;
		for (int i = 1; i < deck->size; i++) {
            deck->cards[i - 1] = deck->cards[i];
        }
		deck->size--;
		deck->cards = (Card *)realloc(deck->cards, deck->size * sizeof(Card));	
	}	
}

#endif