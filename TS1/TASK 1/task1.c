#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define MULT '*'
#define MOD '%'
#define FINISH '\0'
#define INT '0'

struct token{
	int value;
	char kind;
};

char expr[100];
int where=0 ;

void skipwhite() {
	while (isspace(expr[where])){
		where++;
	}
}

void skipdigit(){
	while (isdigit(expr[where])){
		where++;
	}
}

struct token getnexttoken(){

	struct token token;
	skipwhite();
	sscanf(&expr[where] , "%d" , &token.value);
    if(isdigit(expr[where])){
		token.kind = INT;
		skipdigit();
	}
	else{
		token.kind=expr[where];
		where++;
	}
	return token;
};



int main(){
	struct token token;
	int i;
	printf("Input expression:");
	fgets(expr, 99, stdin);
	token = getnexttoken();
	while (token.kind != FINISH)
	{
	printf("%c", token.kind);
	if (token.kind == INT){
		printf(" %d", token.value);
	}
	printf("\n");
	token = getnexttoken();
	}
	return 0;
}
