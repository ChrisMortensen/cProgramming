#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int guess;
	srand(time(NULL));
	printf("Make a guess 1-10:\n");
	printf("Guess : ");
	scanf(" %d", &guess);

	int randomNumbers[3];
	for (int i = 0; i < 3; i++)
	{
		int random;
		do
		{
			random = rand() % 10 + 1;

		} while (random == randomNumbers[0] || random == randomNumbers[1]);
		randomNumbers[i] = random;
	}
	if (guess == randomNumbers[0] || guess == randomNumbers[1] || guess == randomNumbers[2])
	{
		printf("The guess was right!\n");
	}
	else
	{
		printf("Your guess was wrong!\n");
	}
	printf("The numbers were:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Number %d : %d\n", i + 1, randomNumbers[i]);
	}

	return 0;
}