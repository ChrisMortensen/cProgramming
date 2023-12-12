/*
        Navn			:	Christian Svalgaard Mortensen
        Email			:	csmo23@student.aau.dk
        Gruppe			:	1
        Studieretning	:	Cyber- og computer teknologi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[4];
    int point;
    int goals;
    int concededGoals;
} club;

typedef struct {
    char weekday[4];
    int date[2];
    int time[2];
    char teams[2][4];
    int result[2];
    int spectators;

} match;

match *loadMatches(FILE *file, int *matchesCount);
void instantiateClub(club *c, char name[]);
void addMatch(club *c, match m, int team);
void newClub(club **clubs, char name[], int *clubsCount);
void matchConversion(club **clubs, match match, int *clubsCount);
void loadStats(club **clubs, match *matches, int matchesCount, int *clubsCount);
int compareClubs(const void *a, const void *b);
void printResult(club *clubs, int clubsCount);

int main(void) {
	//	Load Matches from file into match-structs
    FILE *inputFile = fopen("kampe-2023-2024.txt", "r");
    int matchesCount = 0;
    match *matches = loadMatches(inputFile, &matchesCount);
    fclose(inputFile);

	//	Load Matches from match-structs into array of club-structs
    int clubsCount = 0;
    club *clubs = NULL;
    loadStats(&clubs, matches, matchesCount, &clubsCount);
    free(matches);

	//	Sort clubs in clubs-array
    qsort(clubs, clubsCount, sizeof(club), compareClubs);
	
	//	Print result (Sorted clubs-array)
    printResult(clubs, clubsCount);

    free(clubs);
    return 0;
}

match *loadMatches(FILE *file, int *matchesCount) {
    int i = 0;
    char c[20];
    match *m = NULL;

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        m = (match *)realloc(m, sizeof(match) * (i + 1));
        fscanf(file, "%s %d/%d %d.%d %s - %s %d - %d %d\n", &m[i].weekday,
               &m[i].date[0], &m[i].date[1], &m[i].time[0], &m[i].time[1],
               &m[i].teams[0], &m[i].teams[1], &m[i].result[0], &m[i].result[1],
               &m[i].spectators);
        i++;
    }
    *matchesCount = i;
    return m;
}

void loadStats(club **clubs, match *matches, int matchesCount, int *clubsCount) {
    for (int i = 0; i < matchesCount; i++) {
        matchConversion(clubs, matches[i], clubsCount);
    }
}

void matchConversion(club **clubs, match match, int *clubsCount) {
    for (int team = 0; team < 2; team++) {
        int i = 0;
        int found = 0;
        while (i < (*clubsCount) && found != 1) {
            if (strcmp((*clubs)[i].name, match.teams[team]) == 0) {
                addMatch(&(*clubs)[i], match, team);
                found = 1;
            }
            i++;
        }
        if (found == 0) {
            newClub(clubs, match.teams[team], clubsCount);
            addMatch(&(*clubs)[*clubsCount - 1], match, team);
        }
    }
}

void addMatch(club *c, match m, int team) {
    c->goals += m.result[team];
    c->concededGoals += m.result[team ^ 1];
    if (m.result[team] > m.result[team ^ 1]) {
        c->point += 3;
    } else if (m.result[team] == m.result[team ^ 1]) {
        c->point++;
    }
}

void newClub(club **clubs, char name[], int *clubsCount) {
    (*clubsCount)++;
    *clubs = (club *)realloc(*clubs, (*clubsCount) * sizeof(club));
    instantiateClub(&(*clubs)[*clubsCount - 1], name);
}

void instantiateClub(club *c, char name[]) {
    strcpy(c->name, name);
    c->point = 0;
    c->goals = 0;
    c->concededGoals = 0;
}

int compareClubs(const void *a, const void *b) {
    const club *clubA = (const club *)a;
    const club *clubB = (const club *)b;

	//	If they dont have the same amount of points:
	//	Sorts based on the point difference
    if (clubA->point != clubB->point) {
        return clubB->point - clubA->point;
    }
	//	If they do have the same amount of points:
	// Sorts based on the difference between goals scored and goals let in
    return (clubB->goals - clubB->concededGoals) -
           (clubA->goals - clubA->concededGoals);
}

void printResult(club *clubs, int clubsCount) {
    printf("Club  Points  Goals  C-Goals\n");
    printf("----------------------------\n");
    for (int i = 0; i < clubsCount; i++) {
        printf("%-3s     %02d     %02d      %02d\n", clubs[i].name,
               clubs[i].point, clubs[i].goals, clubs[i].concededGoals);
    }
}