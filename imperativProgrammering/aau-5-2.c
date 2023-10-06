#include "aau-5-2.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

void main(){
	int num = 3, wantedPrimes, foundPrimes = 0;
	
	printf("How many primes do you want to find?\n");
	scanf(" %d", &wantedPrimes);

	if (wantedPrimes > 0)
	{
		foundPrimes++;
		printf("prime %3d: %3d\n", foundPrimes, num);
	}
	
	while (foundPrimes < wantedPrimes)
	{
		if(is_prime(num)){
			foundPrimes++;
			printf("prime %3d: %3d\n", foundPrimes, num);
		}
		num+=2;
	}
	return;
}

/* Return if i is a prime number. 
   It is assumed as a precondition that the parameter i is non-negative */
int is_prime(int i){
   assert(i >= 0);

   if (i == 1) 
     return 0;
   else if (i == 2) 
     return 1;
   else if (i % 2 == 0)
     return 0;
   else{
     int k, limit;
     limit = (int)(ceil(sqrt(i)));
     for (k = 3; k <= limit; k += 2)
        if (i % k == 0)
           return 0;
     return 1;
   }
}