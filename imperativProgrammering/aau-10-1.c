#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	char *str = "testing";
	char *rts = strrev(str);

	printf("Old : %s\n", str);
	printf("New : %s\n", rts);

	return 0;
}

char *strrev (char *str){
	int length = strlen(str);
	char *rts = (char *)malloc(length);
	for (int i = 0; i < length; i++)
	{
		rts[length - i - 1] = str[i];
	}
	return rts;
}