#include <stdio.h>
#include <stdbool.h>

// Sten , Saks papir program der tager to input og beregner om spiller 1 har vundet
int main (void) {
  char spiller1sHaand;
  char spiller2sHaand;
  int spiller1Vandt, uafgjort;
  
  printf ("GIv spiller1s haand (r for sten, s saks og p for papir)\n");
  scanf ("%c",&spiller1sHaand);
  printf ("GIv spiller2s haand (r for sten, s saks og p for papir)\n");
  scanf (" %c",&spiller2sHaand);

  uafgjort = spiller1sHaand==spiller2sHaand ? true : false;
  spiller1Vandt = (spiller1sHaand == 'r' && spiller2sHaand == 's') ||
    (spiller1sHaand == 's' && spiller2sHaand == 'p') ||
    (spiller1sHaand == 'p' && spiller2sHaand == 'r');

if (uafgjort)
{
  printf ("Spillet er uafgjort\n");
} else {
  printf ("SPiller 1 vandt: %d\n",spiller1Vandt);
}

  
}
