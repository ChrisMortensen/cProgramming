#include <stdio.h>

void main(){

	int n, different, total;

	scanf(" %d", &n);

	for (int i = 1; i <= n; i++)
	{
		total+=i;
	}
	
	different = (n * (n + 1)) / 2 != n ? 1 : 0;
	printf("%d\n", different);

	return;
}