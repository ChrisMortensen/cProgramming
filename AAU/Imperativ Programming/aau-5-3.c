#include <stdio.h>
#include <math.h>
#include <assert.h>

int is_prime(int);

int main(void){
	int min, max;

	printf("Please provide the interval:\n");
	printf("Min : ");
	scanf(" %d", &min);
	printf("Max : ");
	scanf(" %d", &max);

	if (min % 2 == 1){
		min++;
	}

	for (int n = min; n <= max; n+=2)
	{
		int i = 1;
		do
		{
			i+=2;
			
		} while (!is_prime(i) || !is_prime(n-i));
		printf("%d = %d + %d.\n",n, i, n-i);
	}
	
	return 0;
}

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