#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	
	FILE *f2 = fopen("text.txt", "r");
	planet *p = loadPlanets(f2);
	fclose(f);
	fclose(f2);
	printf("%s\n",p[0].name); 
	
	return 0;
}

planet *loadPlanets(FILE *f){
	planet *p = (planet *) malloc(sizeof(planet));
	int i = 0;
	char *c;
	fscanf(f, "%s", &c);
	printf("%s", c);
	while (c =="-")
	{
		printf("%d",i);
		p = (planet *) realloc(p,sizeof(planet) * (i + 1));
		fscanf(f, "%s %lf %lf", p[i].name, &p[i].mass, &p[i].volume);
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
}

double returnDencity(planet p){
	return p.mass/p.volume;
}