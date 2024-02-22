#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	char name[20];
	double volume;
	double mass;
} planet;

double returnDencity(planet p);
void savePlanets (FILE *f, planet planets[], int length);
planet *loadPlanets(FILE *f);

int main(void){
	planet earth={
		"Earth",
		1.08321e12,
		5.972168e24
	};
	planet mars={
		"Mars",
		1.63118e11,
		6.4171e23
	};
	planet planets[2] = {earth, mars};
	FILE *f = fopen("text.txt", "w");
	int length = (int)(sizeof(planets) / sizeof(planet));
	savePlanets(f, planets, length);
	fclose(f);
	
	FILE *f2 = fopen("text.txt", "r");
	planet *p = loadPlanets(f2);
	fclose(f2);

	printf("%s\n",p[1].name); 
	
	return 0;
}

planet *loadPlanets(FILE *f){
	int i = 0;
	char c[20];
	planet *p = (planet *) malloc(sizeof(planet));
	
	fscanf(f, "%s", &c);
	while (strcmp(c,"END") != 0)
	{
		p = (planet *) realloc(p,sizeof(planet) * (i + 1));
		strcpy(p[i].name, c);
		fscanf(f, "%lf %lf", &p[i].mass, &p[i].volume);
		i++;
		fscanf(f, "%s", &c);
	}
	return p;
}

void savePlanets (FILE *f, planet planets[], int length){
	for (int i = 0; i < length; i++)
	{
		fprintf(f, "%s %e %e\n", planets[i].name, planets[i].mass, planets[i].volume);
	}
	fprintf(f, "END\n");
}

double returnDencity(planet p){
	return p.mass/p.volume;
}