#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlink.c"

char tmp[101];



int rollDice(){
	int i = 1+rand()%6;
	return i;
}

int main(){
	char *name;
	int dice;
	init();
	FILE *playerF = fopen("players","r");
	assert(playerF != NULL); // File is open
	fgets(tmp, 100, playerF);

	while (!feof(playerF)) {
		// Get space filled with \0
		name = calloc(1,strlen(tmp)+1);
		// Newline should not copied
		strncpy(name, tmp, strlen(tmp)-1);
		insertchair(name);
		fgets(tmp, 100, playerF);
	}
	
	printf("\nAll palyers are in their chairs now. Game begins\n\n");
	
	/*while (isempty()!=-1){
		printf("%s is in chair 0. \n", whoinchair());
		dice = rollDice();
		if (dice%2 == 1){ // Odd numbers on left!
			dice *= -1;
		}
		printf("Rid chair %d.\n", dice);
		name = removechair(dice);
		if (isempty()==-1)
			printf("\n\nWinner is %s\n", name);
		else
		printf("\nLosing player was %s.\n", name);
		free(name);
	}*/
	/*printf("\nLosing player was %s.\n", removechair(-1));
	printf("\nLosing player was %s.\n", removechair(-2));
	printf("\nLosing player was %s.\n", removechair(4));
	printf("\nLosing player was %s.\n", removechair(2));
	printf("\nLosing player was %s.\n", removechair(-5));*/





	return 0;
}