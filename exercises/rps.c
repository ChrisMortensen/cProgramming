#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void main(){

	char pHand,cHand;
	int winner;

	printf("Choose your hand (r for rock, p for paper or s for scissors):\n");
	scanf("%c", &pHand);

	if (pHand != 'r' && pHand != 'p' && pHand != 's')
	{
		printf("Error! Please provide a valid input.\n");
		return;
	}
	
	srand(time(NULL));
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		cHand = 'r';
		printf("The computer chose rock.\n");
		break;
	case 1:
		cHand = 'p';
		printf("The computer chose paper.\n");
		break;
	case 2:
		cHand = 's';
		printf("The computer chose stone.\n");
		break;
	default:
		break;
	}

	winner = 
	pHand == 'r' && cHand == 's' ? 1 : 
	pHand == 'p' && cHand == 'r' ? 1 : 
	pHand == 's' && cHand == 'p' ? 1 : 
	pHand == cHand ? 0 : 2;

	switch (winner)
	{
	case 0:
		printf("It's a tie\n");
		break;
	case 1:
		printf("You win\n");
		break;
	case 2:
		printf("The computer wins\n");
		break;
	default:
		break;
	}

	return;
}