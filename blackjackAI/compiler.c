#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include "ai.h"
#define GENERATIONS 2
#define PLAYEDHANDS 10


void beforeStart();

int main(void)
{
	Generation generations[GENERATIONS];
	beforeStart();
	generations[0] = firstGeneration();
	//fitnessScore(&generations[0],PLAYEDHANDS);
	findParents(generations[0]);
	for (int generationID = 1; generationID < GENERATIONS; generationID++)
	{
		generations[generationID] = newGeneration(generations[generationID-1]);
		printf("\n\nTest : %d\n\n",generations[0].population[0].hardTable[0][0]);
		//fitnessScore(&generations[generationID], PLAYEDHANDS);
		findParents(generations[generationID]);
	}
	return 0;
}

void beforeStart()
{
	srand(time(NULL));
}

