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
	fitnessScore(generations[0],PLAYEDHANDS);
	findParents(generations[0]);
	for (int generationID = 1; generationID < GENERATIONS; generationID++)
	{
		generations[generationID] = newGeneration(generations[generationID-1]);
		freeGeneration(generations[generationID-1]);
		fitnessScore(generations[generationID], PLAYEDHANDS);
		findParents(generations[generationID]);
	}
	return 0;
}

void freeGeneration(Generation gen){
	for (int parentID = 0; parentID < PARENTS; parentID++) {
    	free(gen.bestOfPopulation[parentID]);
	}
	free(gen.bestOfPopulation);
	for (int aiID = 0; aiID < POPULATIONSIZE; aiID++) {
		free(gen.population[aiID].hardTable);
		free(gen.population[aiID].softTable);
		}
	free(gen.population);
}

void beforeStart()
{
	srand(time(NULL));
}

