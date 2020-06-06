#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "s.c"
#define LPAR '('
#define RPAR ')'
#define MOD '%'
#define MULT '*'
#define INT '0'
#define PLUS '+'
#define FINISH '\0'

char a[100];
int where=0;

struct token{
	int value;
	char kind;
};

void skipdigits(){
	while(isdigit(a[where])){
		where++;
	}
}

void skipspace(){
	while(isspace(a[where])){
		where++;
	}
}

struct token getnexttoken(){
	struct token token;
	skipspace();
	sscanf(&a[where],"%d" , &token.value);
	if(isdigit(a[where])){
		token.kind=INT;
		skipdigits();
	}
	else{
		token.kind=a[where];
		where++;
	}
	return token;
}

int main(){
	struct token token;
	printf("Input Expression : ");
	fgets(a,100,stdin);
	token=getnexttoken();
	init();
	while(token.kind!=FINISH){
		if(token.kind==INT){
			printf("%d" , token.value);
		}
		else{
			switch(token.kind){
				case '(':
					push(token.kind);
					break;
				case '+':
					if(getp(peek())>getp(token.kind)){
						while(getp(peek())>getp(token.kind)){
							printf("%c " ,pull());
						}
					}
					push(token.kind);
					break;
				case '-':
					if(getp(peek())>getp(token.kind)){
						while(getp(peek())>getp(token.kind)){
							printf("%c " ,token.kind);
						}
					}
					push(token.kind);
					break;
				case '*':
					if(getp(peek())>getp(token.kind)){
						while(getp(peek())>getp(token.kind)){
							printf("%c " ,token.kind);
						}
					}
					push(token.kind);
					break;
				case '/':
					if(getp(peek())>getp(token.kind)){
						while(getp(peek())>getp(token.kind)){
							printf("%c " ,token.kind);
						}
					}
					push(token.kind);
					break;
				case '%':
					push(token.kind);
					break;
				case ')':
					while(peek()!='('){
                        printf("%c " , pull());
                    }
                    pull();
                    break;
			}
		}
		token=getnexttoken();
	}
	/*push(2);
	push(3);
	pull();
	pull();*/
}