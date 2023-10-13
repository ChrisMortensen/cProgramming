#ifndef AI_H
#define AI_H

#define POPULATIONSIZE 10
#define GENERATIONAMOUNT 10

typedef struct
{
	int hardTable[10][20];
	int softTable[10][8];
	int fitness;
} Ai;

typedef struct
{
	Ai population[POPULATIONSIZE];

} Generation;


Generation firstGeneration(){
	Generation gen;
	for (int ai = 0; ai < POPULATIONSIZE; ai++) {
		gen.population[ai] = *(Ai *)malloc(sizeof(Ai));
		for (int dealerUpcard = 0; dealerUpcard < 10; dealerUpcard++) {
			for (int hardTotal = 0; hardTotal < 20; hardTotal++) {
				gen.population[ai].hardTable[dealerUpcard][hardTotal] = rand() % 3;
			}
			for (int softTotal = 0; softTotal < 8; softTotal++) {
				gen.population[ai].softTable[dealerUpcard][softTotal] = rand() % 3;
			}
		}
	}
	return gen;
}

/*
void fitnessScore(int totalGames){}
void dealerTurn(){}
void createChildren(){}
void mutatePopulation(){}
void checkForBlackjack(){}
void checkforAces(){}
*/

#endif