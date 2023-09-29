#include <stdio.h>


void main(){
	int n, m;

	scanf(" %d", &n);

	for (int i = 0; i <= n; i++)
	{
		printf("\n%2d",i);
		for (int j = 0; j < n-i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
	}

	return;
}