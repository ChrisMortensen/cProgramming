#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5;
  int res1, res2, res3;
  
  i++; j--; ++k;

  printf("i: %d, j: %d, k: %d\n", i,j,k); 
  //	i: 4, j: 3, k: 6

  res1 = --i;
  res2 = j++;
  res3 = --k;

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3);
  //	res1: 3, res2: 3, res3: 5
  printf("i: %d, j: %d, k: %d\n", i,j,k);
  //	i: 3, j: 4, k: 5
  
  return 0;
}