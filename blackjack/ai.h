#ifndef AI_H
#define AI_H

#define POPULATIONSIZE 10
#define PARENTS 5
#define CHILDREN POPULATIONSIZE/PARENTS
#define MUTATIONCHANCE 10 //One out of MUTATIONCHANCE

typedef struct
{
	int hardTable[10][20];
	int softTable[10][8];
	int fitness;
} Ai;

typedef struct
{
	Ai population[POPULATIONSIZE];
	Ai* bestOfPopulation[PARENTS];

} Generation;

void findParents(Generation gen){
	for (int i = 0; i < PARENTS; i++) {
        gen.bestOfPopulation[i] = &gen.population[i];
    }
	for (int ai = PARENTS; ai < POPULATIONSIZE; ai++)
	{
		int worstIndex = 0;
        for (int i = 1; i < PARENTS; i++) {
            if (gen.bestOfPopulation[i]->fitness < gen.bestOfPopulation[worstIndex]->fitness) {
                worstIndex = i;
            }
        }
		if (gen.population[ai].fitness > gen.bestOfPopulation[worstIndex]->fitness) {
            gen.bestOfPopulation[worstIndex] = &gen.population[ai];
        }
	}
}

Generation createGen(){
	Generation gen;
	for (int ai = 0; ai < POPULATIONSIZE; ai++) {
		gen.population[ai] = *(Ai *)malloc(sizeof(Ai));
		gen.population[ai].fitness = 0;
	}
	return gen;
}

Generation firstGeneration(){
	Generation gen = createGen();
	for (int ai = 0; ai < POPULATIONSIZE; ai++) {
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

void createChildren(Generation priorGen, Generation *gen){
	for (int parentID = 0; parentID < PARENTS; parentID++)
	{
		for (int childID = 0; childID < CHILDREN; childID++)
		{
			for (int dealerUpcard = 0; dealerUpcard < 10; dealerUpcard++) {
				Ai parent = *(priorGen.bestOfPopulation[parentID]);
				for (int hardTotal = 0; hardTotal < 20; hardTotal++) {
					gen->population[parentID * CHILDREN + childID].hardTable[dealerUpcard][hardTotal] = parent.hardTable[dealerUpcard][hardTotal];
				}
				for (int softTotal = 0; softTotal < 8; softTotal++) {
					gen->population[parentID * CHILDREN + childID].softTable[dealerUpcard][softTotal] = parent.softTable[dealerUpcard][softTotal];
				}
			}
		}
		
	}
}

void mutatePopulation(Generation *gen){
	for (int ai = 0; ai < POPULATIONSIZE; ai++)
	{
		for (int dealerUpcard = 0; dealerUpcard < 10; dealerUpcard++) {
			for (int hardTotal = 0; hardTotal < 20; hardTotal++) {
				if(rand() % MUTATIONCHANCE == 0){
					gen->population[ai].hardTable[dealerUpcard][hardTotal] = rand() % 3;
				}
			}
			for (int softTotal = 0; softTotal < 8; softTotal++) {
				if(rand() % MUTATIONCHANCE == 0){
					gen->population[ai].softTable[dealerUpcard][softTotal] = rand() % 3;
				}
			}
		}
	}
}

Generation newGeneration(Generation priorGen){
	Generation gen = createGen();
	createChildren(priorGen, &gen);
	mutatePopulation(&gen);
	return gen;
}

void fitnessScore(Generation gen, int totalGames){}

void dealerTurn(){}


#endif