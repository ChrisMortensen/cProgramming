#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void main(){

	char p1Hand,p2Hand;
	int winner;

	printf("Choose your hand (r, p or s):\n");
	scanf("%c", &p1Hand);

	srand(time(NULL));
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		p2Hand = 'r';
		printf("The computer chose rock.\n");
		break;
	case 1:
		p2Hand = 'p';
		printf("The computer chose paper.\n");
		break;
	case 2:
		p2Hand = 's';
		printf("The computer chose stone.\n");
		break;
	default:
		break;
	}

	winner = 
	p1Hand == 'r' && p2Hand == 's' ? 1 : 
	p1Hand == 'p' && p2Hand == 'r' ? 1 : 
	p1Hand == 's' && p2Hand == 'p' ? 1 : 
	p1Hand == p2Hand ? 0 : 2;

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