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