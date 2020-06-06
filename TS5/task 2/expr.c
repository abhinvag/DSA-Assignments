#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

void create_expr(expression *ptrToExpr){
	(*ptrToExpr) = malloc(sizeof(struct term));
	(*ptrToExpr)->next = NULL;
	return;
}

void insertTerm(expression *ptrToExpr , int coeff , int power){
	struct term *newterm = (struct term*)malloc(sizeof(struct term));
	struct term *ptr,*prev;
	newterm->power = power;
	newterm->coeff = coeff;

	prev = *ptrToExpr;
	ptr = getFirstTerm(ptrToExpr);
	while(ptr!=NULL && power<ptr->power){
		prev=ptr;
		ptr = getNextTerm(ptr);
	}
	newterm->next = ptr;
	prev->next = newterm;
	return; 
}

struct term *getFirstTerm(expression *ptrToExpr){
	return (*ptrToExpr)->next;
}

struct term *getNextTerm(struct term *term){
	return term->next;
}


static void printTerm(struct term *term) {
	printf("%+d*X^%d ", term->coeff,term->power);
}

void printExpr(expression *ptrToExpr) {
	struct term *prnt = getFirstTerm(ptrToExpr);
	while (prnt!=NULL){
		printTerm(prnt);
		prnt = getNextTerm(prnt);
	}
	printf("\n");
}

void addTerm(expression *prtToExpr, int coeff, int power){
	int flag = 0;
	struct term *ptr,*prev;
	ptr = getFirstTerm(prtToExpr);
	prev = *prtToExpr;
	while(ptr!=NULL){
		if(ptr->power==power){
			flag=1;
			break;
		}
		prev = ptr;
		ptr = getNextTerm(ptr);
	}
	if(flag==1){
		ptr->coeff += coeff;
		if(ptr->coeff==0){
			prev->next = ptr->next;
			free(ptr);
		}
		printf("added\n");
		return ; 
	}
	else{
		insertTerm(prtToExpr , coeff  , power);
		printf("added");
		return;
	}
}

struct term *searchTerm(expression *prtToExpr, int pow){
	struct term *ptr = getFirstTerm(prtToExpr);
	struct term *prev = *prtToExpr;
	while(ptr->power>=pow){
		if(ptr->power==pow){
			printf("Term found\n");
			return ptr;
		}
		prev = ptr;
		ptr = getNextTerm(ptr);
	}
	return ptr;
}

void makeExprCopy(expression *srcExpr, expression *dstExpr){
	create_expr(dstExpr);
	struct term *ptr = getFirstTerm(srcExpr);
	while(ptr!=NULL){
		insertTerm(dstExpr , ptr->coeff , ptr->power);
		ptr = getNextTerm(ptr);
	}
	return;
}