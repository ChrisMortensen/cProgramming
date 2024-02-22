#include <stdio.h>

int main(void) {
	int i, j, small, large, remainder;
 
	printf("Enter two positive integers: ");
	scanf("%d %d", &i, &j);

	small = i <= j ? i : j;
	large = i <= j ? j : i;
	while (small > 0){
		remainder = large % small;
		large = small;
		small = remainder;
	}

	printf("GCD of %d and %d is %d\n\n", i, j, large);
	
	return 0;
}	 