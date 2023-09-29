#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	srand(time(NULL));
	int rnd = rand() % 21, guess = -1, guessTotal = 0;

	do {
		printf("Please provide a guess [0-20]:\n");
		scanf(" %d", &guess);
		while(guess<0||guess>20){
			printf("Thats not within the guessing range [0-20].\n Please provide a new guess:\n");
			scanf(" %d", &guess);
		}
		if (guess > rnd)
		{
			printf("Thats too high! Try again!\n");
		}
		else if (guess < rnd)
		{
			printf("Thats too low! Try again!\n");
		}
		guessTotal++;
	} while(rnd != guess);

	printf("Thats right!\n It took you %d guesses",guessTotal);

	return;
}