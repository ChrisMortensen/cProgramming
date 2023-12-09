#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[4];
	int point;
	int goals;
	int concededGoals;
} club;

typedef struct
{
	char weekday[4];
	int date[2];
	int time[2];
	char teams[2][4];
	int result[2];
	int spectators;

} match;

match *loadMatches(FILE *file, int *matchesCount){
	int i = 0;
	char c[20];
	match *m = NULL;
	
	int ch;
    while ((ch = fgetc(file)) != EOF)
	{
		m = (match *) realloc(m,sizeof(match) * (i + 1));
		fscanf(file, "%s %d/%d %d.%d %s - %s %d - %d %d\n",
		&m[i].weekday,
		&m[i].date[0], &m[i].date[1], 
		&m[i].time[0], &m[i].time[1], 
		&m[i].teams[0], &m[i].teams[1], 
		&m[i].result[0], &m[i].result[1], 
		&m[i].spectators);
		i++;
	}
	*matchesCount = i;
	return m;
}

void printMatch(match m){
	printf("%s    %d/%d %d.%d    %s - %s    %d - %d    %d\n",
    m.weekday,
	m.date[0], m.date[1], 
    m.time[0], m.time[1], 
    m.teams[0], m.teams[1], 
    m.result[0], m.result[1], 
    m.spectators);
}

void printClub(club c){
	printf("Name : %s\nPoints : %d\nGoals : %d\nConceded Goals : %d\n", c.name, c.point, c.goals, c.concededGoals);
}

void instantiateClub(club *c, char name[]){
	strcpy(c->name, name);
	c->point = 0;
	c->goals = 0;
	c->concededGoals = 0;
}

void addMatch(club *c, match m, int team){
	c->goals += m.result[team];
	c->concededGoals += m.result[team ^ 1];
	if (m.result[team] > m.result[team ^ 1])
	{
		c->point += 3;
	} else if (m.result[team] == m.result[team ^ 1])
	{
		c->point++;
	}			
}

void newClub(club **clubs, char name[], int *clubsCount){
	(*clubsCount)++;
	*clubs = (club *)realloc(*clubs, (*clubsCount) * sizeof(club));
	instantiateClub(&(*clubs)[*clubsCount - 1], name);
}

void matchConversion(club **clubs, match match, int *clubsCount){
	for (int team = 0; team < 2; team++)
	{	
		int i = 0;
		int found = 0;
		while (i < (*clubsCount) && found != 1)
		{
			if (strcmp((*clubs)[i].name, match.teams[team]) == 0)
			{
				addMatch(&(*clubs)[i], match, team);
				found = 1;
			}
			i++;
		}
		if (found == 0){
			newClub(clubs, match.teams[team], clubsCount);
			addMatch(&(*clubs)[*clubsCount - 1], match, team);
		}
	}
}

void loadStats(club **clubs, match *matches, int matchesCount){
	int clubsCount = 0;
	for (int i = 0; i < matchesCount; i++){
		matchConversion(clubs, matches[i], &clubsCount);
	}
}

int main(void) {
	FILE *f = fopen("kampe-2023-2024.txt", "r");
	int matchesCount = 0;
	match *matches = loadMatches(f, &matchesCount);
	club *clubs = NULL;
	loadStats(&clubs, matches, matchesCount);
	
	for (int i = 0; i < 12; i++)
	{
		printf("\nCLUB_NR : %d\n", i + 1);
		printClub(clubs[i]);
	}
	
    fclose(f);
	free(matches);
	free(clubs);
	return 0;
}