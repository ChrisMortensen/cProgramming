#include <stdio.h>


void main(){

	int n;

	scanf(" %d", &n);

	for (int i = 0; i <= n; i++)
	{
		printf("\n");
		for (int j = 0; j <= i; j++)
		{
			printf("%d ",j);
		}
		
	}
	
	for (int i = 0; i <= n; i++)
	{
		printf("\n");
		for (int j = 0; j < n-i; j++)
		{
			printf("%d ",j);
		}
		
	}
	return;
}