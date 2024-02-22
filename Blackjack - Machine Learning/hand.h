#ifndef HAND_H
#define HAND_H

typedef struct
{
	Card *cards;
	int size;
	int sum;
	int soft;
} Hand;

#endif