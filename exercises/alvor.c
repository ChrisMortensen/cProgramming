#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alvor(char s1[]);
int main (void){
	char s[] = "Anders";

	char *s2 = alvor(s);

	printf("Old : %s\n", s);
	printf("New : %s\n", s2);

	free(s2);
	return 0;
	
}

char *alvor(char s1[]){
	char *s2 = (char *) malloc(strlen(s1)+1);
	for (int i = 0; i < strlen(s1); i++)
	{
		s2[i] = s1[i];
	}
	s2[strlen(s1)] = '!';
	return s2;
}