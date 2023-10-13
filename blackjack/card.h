#ifndef CARDS_H
#define CARDS_H

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
	int value;
} Card;

#endif