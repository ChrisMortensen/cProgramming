#include <stdio.h>
#include <ctype.h>

int main(void){

	char s[] = "Hus";
	printf("String : %s\n", s);
	int count = 0;
	for (int i = 0; s[i] != '\0' ; i++)
	{
		if (islower(s[i]))
		{
			count++;
		}	
	}
	printf("Lowercase :  %2d", count);

	return 0;
}