#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int key;
	char *name;
	int point;
	int goals;
	int concededGoals;
} club;

typedef struct
{
	char weekday[4];
	int date[2];
	int time[2];
	char *teams[2][4];
	int result[2];
	int spectators;

} match;

int hashKey(char *str){
	return str[0] * 10000 + str[1] * 100 + str[2];
}

match *loadMatches(FILE *f){
	int i = 0;
	char c[20];
	match *m = (match *) malloc(sizeof(match));
	
	while (fscanf(f, "%s", c) != EOF)
	{
		m = (match *) realloc(m,sizeof(match) * (i + 1));
		strcpy(m[i].weekday, c);
		fscanf(f, "%d/%d %d.%d %s - %s %d - %d %d",
		&m[i].date[0], &m[i].date[1], 
		&m[i].time[0], &m[i].time[1], 
		&m[i].teams[0], &m[i].teams[1], 
		&m[i].result[0], &m[i].result[1], 
		&m[i].spectators);
		i++;
	}
	return m;
}

void printMatch(match m){
	printf("%s    %d/%d %d.%d    %s - %s    %d - %d    %d",
    m.weekday,
	m.date[0], m.date[1], 
    m.time[0], m.time[1], 
    m.teams[0], m.teams[1], 
    m.result[0], m.result[1], 
    m.spectators);
}

club *loadStats(){
	club *temp;
	return temp;
}

int main(void) {
	FILE *f = fopen("kampe-2023-2024.txt", "r");
	match *matches = loadMatches(f);
	printMatch(matches[0]);

	club *clubs = loadStats();
    
	return 0;
}