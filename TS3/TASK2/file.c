#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *pf;
	char ch;
	pf = fopen("copiedprogram.c" , "r");
	while(!feof(pf)){
		ch = fgetc(pf);
		printf("%c",ch);
	}
	fclose(pf);
	return 0;
}