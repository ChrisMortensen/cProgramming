#include <stdio.h>


void main (){

	int PH;
	char* text;

	printf("Enter PH-value:\n");
	scanf("%d", &PH);

	if (PH<=7){
		if(PH==7){
			text = "Neutral.\n";
		}
		if(PH>2){
			text = "Acidic.\n";
		}else{
			text = "Very acidic.\n";
		}
	} else{
		if(PH<12){
			text = "Alkaline.\n";
		}  else
		{
			text = "Very alkaline.\n";
		}
	}

	printf("%s",text);
	return;
}