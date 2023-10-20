#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
	guacamole,
	tarteletter,
	lakserulle,
	graeskarsuppe
} Forret;

typedef enum
{
	gyldenkaal,
	hakkeboef,
	gullash,
	forloren_hare
} Hovedret;

typedef enum
{
	pandekager_med_is,
	gulerodskage,
	choklademousse,
	citronfromage
} Desert;

const char* forretNames[]=
{
	"guacamole",
	"tarteletter",
	"lakserulle",
	"graeskarsuppe"
};

const char* hovedretNames[]=
{
	"gyldenkaal",
	"hakkeboef",
	"gullash",
	"forloren_hare"
};

const char* desertNames[]=
{
	"pandekager_med_is",
	"gulerodskage",
	"choklademousse",
	"citronfromage"
};

void maaltid(Forret *forret, Hovedret *hovedret, Desert *desert);
void printMenu(Forret forret, Hovedret hovedret, Desert desert, int menuNr);

int main(void)
{
	Forret forret;
	Hovedret hovedret;
	Desert desert;
	srand(time(NULL));
	for (int menuNr = 1; menuNr <= 25; menuNr++)
	{
		maaltid(&forret, &hovedret, &desert);
		
		printMenu(forret, hovedret, desert, menuNr);
	}
	return 0;
}

void maaltid(Forret *forret, Hovedret *hovedret, Desert *desert)
{
	*forret = rand() % 4;
	*hovedret = rand() % 4;
	*desert = rand() % 4;
}

void printMenu(Forret forret, Hovedret hovedret, Desert desert, int menuNr)
{
	printf("\n%d. Menu\n",menuNr);
	printf("Forret   : %s\n",forretNames[forret]);
	printf("Hovedret : %s\n",hovedretNames[hovedret]);
	printf("Desert   : %s\n",desertNames[desert]);

}