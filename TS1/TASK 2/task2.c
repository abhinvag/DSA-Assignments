#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define MULT '*'
#define MOD '%'
#define FINISH '\0'
#define INT '0'
#define MAX 100
int top = -1;
void push(float st[],float val);
float st[MAX];
float peek(float st[]);
float pop(float st[]);

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
	float a,b,value;
	printf("Input expression: ");
	fgets(expr, 99, stdin);
	token = getnexttoken();
	while (token.kind != FINISH){
        if (token.kind == INT){
            push(st,(float)token.value);
        }
        else{
            a = pop(st);
    		b= pop(st);
    		switch(token.kind){
    			case '+':
    				value = a + b;
    				break;
    			case '*':
    				value = a*b;
    				break;
    			case '-':
    				value = b-a;
    				break;
    			case '/':
    				value = b/a;
    				break;
				case '%':
					value = (int)b%(int)a;
					break;
    		}
    		push(st,value);
        }
        token = getnexttoken();
	}
	printf("%.02f" , peek(st));
	return 0;
}


void push(float st[],float val){
    if(top==MAX-1){
        printf("stack overflow\n");
        }
    else{
        top++;
        st[top]=val;
        }
}

float peek(float st[]){
    if(top==-1){
        printf("stack empty\n");
        return -1;
    }
    else{
        float v;
        v = st[top];
        return v;
    }
}

float pop(float st[]){
    if(top==-1){
        printf("stack empty\n");
        return -1;
    }
    else{
        float v;
        v = st[top];
        top--;
        return v;
    }
}
