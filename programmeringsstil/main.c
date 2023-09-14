#include <stdio.h>  

void main(){
  float first_number, secondNumber, thirdNumber;

  printf("Give me three: ");
  scanf("%f %f %f", &first_number, &secondNumber, &thirdNumber);
  printf("Theresult: %f\n", (first_number+secondNumber+thirdNumber) / 3.0); 
  scanf("");
  return;
}