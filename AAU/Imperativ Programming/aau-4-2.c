#include <stdio.h>


void main(){

	int n, m, k, sum;

	printf("Please provide the values for m, n and k:\n");
	scanf(" %d %d %d", &m, &n, &k);

	for (int i = m; i <= n; i++)
	{
		sum+= i%k==0 ? i : 0;
	}

	printf("%d", sum);

	return;
}