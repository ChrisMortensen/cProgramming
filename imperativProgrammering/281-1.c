#include <stdio.h>


void main(){

	int population, countYears = 0, wantedPopulation, growth;
	printf("Please write the size of the current population:\n");
	scanf(" %d", &population);
	
	printf("Please write the wanted size of population:\n");
	scanf(" %d", &wantedPopulation);
	printf("Please write the expected annual populationgrowth in percent:\n");
	scanf(" %d", &growth);
	
	while (population < wantedPopulation)
	{
		population *= 1 + growth / 100;
		countYears ++;
	}

	printf("It will take %d years before the oppulation reaches %d.\n",countYears);

	return;
}