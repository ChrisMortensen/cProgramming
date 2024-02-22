#include <stdio.h>

void converter(float dollars, float *euros, float *kroner, float *rubles, float *yen);

int main(void){
	float dollars, euros, kroner, rubles, yen;
	/*
	printf("Dollars : ");
	scanf(" %f", &dollars);
	*/
	for (float dollars = 1; dollars <= 100; dollars++)
	{
		converter(dollars, &euros, &kroner, &rubles, &yen);
		printf("Dollars : Euros : Kroner : Rubles : Yen\n");
		printf("%.2f : %.2f : %.2f : %.2f : %.2f\n", dollars, euros, kroner, rubles, yen);
	}
	return 0;
}

void converter(float dollars, float *euros, float *kroner, float *rubles, float *yen){
	*euros = dollars * 0.89;
	*kroner = dollars * 6.66;
	*rubles = dollars * 66.43;
	*yen = dollars * 119.9;
}