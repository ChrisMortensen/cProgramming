#ifndef AI_H
#define AI_H

#define POPULATIONSIZE 100
#define PARENTS 5
#define CHILDREN POPULATIONSIZE/PARENTS
#define MUTATIONCHANCE 10 //One out of MUTATIONCHANCE

typedef struct
{
	int hardTable[10][16];
	int softTable[10][9];
	int fitness;
} Ai;

typedef struct
{
	Ai population[POPULATIONSIZE];
	Ai* bestOfPopulation[PARENTS];

} Generation;

typedef enum {
	stand,
	hit,
	doubleDown
} Action;

void playerTurn(Ai *ai, Game *game, Action action);
void dealerTurn(Game *game, Ai* ai);

void findParents(Generation *gen) {
    for (int i = 0; i < PARENTS; i++) {
        gen->bestOfPopulation[i] = &gen->population[i];
    }
    for (int ai = PARENTS; ai < POPULATIONSIZE; ai++) {
        int worstIndex = 0;
        for (int i = 1; i < PARENTS; i++) {
            if (gen->bestOfPopulation[i]->fitness < gen->bestOfPopulation[worstIndex]->fitness) {
                worstIndex = i;
            }
        }
        if (gen->population[ai].fitness > gen->bestOfPopulation[worstIndex]->fitness) {
            gen->bestOfPopulation[worstIndex] = &gen->population[ai];
        }
    }
}


Generation createGen(){
	Generation gen;
	for (int ai = 0; ai < POPULATIONSIZE; ai++) {
		gen.population[ai].fitness = 0;
	}
	return gen;	
}

Generation firstGeneration(){
	Generation gen = createGen();
	for (int ai = 0; ai < POPULATIONSIZE; ai++) {
		gen.population[ai].fitness = 0;
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

void createChildren(Generation priorGen, Generation *gen) {
    for (int parentID = 0; parentID < PARENTS; parentID++) {
        for (int childID = 0; childID < CHILDREN; childID++) {
            for (int dealerUpcard = 0; dealerUpcard < 10; dealerUpcard++) {
                Ai parent = priorGen.bestOfPopulation[parentID][0];
                Ai *child = &gen->population[parentID * CHILDREN + childID];

                for (int hardTotal = 0; hardTotal < 16; hardTotal++) {
                    child->hardTable[dealerUpcard][hardTotal] = parent.hardTable[dealerUpcard][hardTotal];
                }
                for (int softTotal = 0; softTotal < 9; softTotal++) {
                    child->softTable[dealerUpcard][softTotal] = parent.softTable[dealerUpcard][softTotal];
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

void fitnessScore(Generation *gen, int totalGames){
	for (int AiID = 0; AiID < POPULATIONSIZE; AiID++)
	{
		for (int gameID = 0; gameID < totalGames; gameID++)
		{
			Game game = createGame();
			Ai *ai = &gen->population[AiID];
			ai->fitness--;
			game.bet++;
			Action action;
			if (game.playerHand.sum == 21) {
				dealerTurn(&game, ai);
			}
			do {
				if(game.playerHand.soft == 0) {
					action =ai->hardTable[game.dealerHand.sum - 2][game.playerHand.sum - 4];
				} else	{
					action = ai->softTable[game.dealerHand.sum - 2][game.playerHand.sum - 13];
				}
				playerTurn(ai, &game, action);
				if (game.playerHand.sum == 21) {
					dealerTurn(&game, ai);
				}else if(game.playerHand.sum > 21)
				{
					if (game.playerHand.soft != 0)
					{
						game.playerHand.sum -= 10;
						game.playerHand.soft--;
					} else {
						destroyDeck(&(game.deck));
						action = stand;
					}
				}
			} while (action == hit && game.playerHand.sum != 21);
			destroyDeck(&(game.deck));
		}
	}
}

void playerTurn(Ai *ai, Game *game, Action action){	
	switch (action)
	{
	case stand:
		dealerTurn(game, ai);
		break;
	case hit:
		drawCard(1, &game->deck, &game->playerHand);
		break;
	case doubleDown:
		ai->fitness--;
		game->bet++;
		drawCard(1, &game->deck, &game->playerHand);
		dealerTurn(game, ai);
		break;
	default:
		break;
	}
}

void dealerTurn(Game *game, Ai *ai){
	while (game->dealerHand.sum < 17)
	{
		drawCard(1, &game->deck, &game->dealerHand);
		if (game->dealerHand.sum > 21 && game->dealerHand.soft > 0) {
            game->dealerHand.sum -= 10;
            game->dealerHand.soft--;
        }
	}
	if (game->playerHand.sum > game->dealerHand.sum){
		ai->fitness += 2 * game->bet;
	} else if (game->playerHand.sum == game->dealerHand.sum){
		ai->fitness += game->bet;
	}
	
}

#endif