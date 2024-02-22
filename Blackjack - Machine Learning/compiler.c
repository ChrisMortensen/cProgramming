#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include "ai.h"
#define GENERATIONS 200
#define TOTALHANDS 200

void beforeStart();

int main(void)
{
	beforeStart();
	static Generation generations[GENERATIONS];
	generations[0] = firstGeneration();
	fitnessScore(&generations[0], TOTALHANDS);
	findParents(&generations[0]);

	for (int generationID = 1; generationID < GENERATIONS; generationID++)
	{
		printf("Gen : %3d | Fitness : %d\n", generationID-1, generations[generationID-1].bestOfPopulation[0]->fitness);
		generations[generationID] = newGeneration(generations[generationID-1]);
		fitnessScore(&generations[generationID], TOTALHANDS);
		findParents(&generations[generationID]);

	}
	printf("Gen : %3d | Fitness : %d\n", GENERATIONS - 1, generations[GENERATIONS - 1].bestOfPopulation[0]->fitness);

	printf("End of the program.");
	return 0;
}

void beforeStart()
{
	srand(time(NULL));
}

