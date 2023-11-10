#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makePlural(char s1[]);

int main(void) {
    char s[] = "Andersy";
    char *s2 = makePlural(s);

    printf("Old : %s\n", s);
    printf("New : %s\n", s2);

    free(s2);
    return 0;
}

char *makePlural(char s1[]) {
    int length = strlen(s1);
    char *s2 = (char *)malloc(length + 3);
	
	if (s1[length - 1] == 'y') {
		s2 = (char *)realloc(s2, length - 1);
		strncpy(s2, s1, length - 1); 
		strcat(s2, "ies");
	} else if ((s1[length - 1] == 's' || (s1[length - 1] == 'h' && (s1[length - 2] == 'c' || s1[length - 2] == 's')))) {
		strcpy(s2, s1);
		strcat(s2, "es");
	} else {
		strcpy(s2, s1);
		strcat(s2, "s");
	}
	s2 = (char *)realloc(s2, strlen(s2) + 1);

    return s2;
}
