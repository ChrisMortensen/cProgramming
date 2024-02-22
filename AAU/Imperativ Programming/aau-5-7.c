#include <stdio.h> //Last part of exercise was already made in 281-1.c

int sum_iter(int);
int sum_formula(int);

void main(){
	int n;
	printf("n : ");
	scanf(" %d", &n);
	if(sum_iter(n) == sum_formula(n)){
		printf("They are the same.");
	} else
	{
		printf("They are different.");
	}

	return;
}

int sum_iter(int n){
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum+=i;
	}
	return sum;
}

int sum_formula(int n){
	return (n + 1)* n / 2;
}