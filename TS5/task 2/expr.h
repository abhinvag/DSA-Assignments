#include <stdio.h>
#include <stdlib.h>

struct term{
	int power;
	int coeff;
	struct node *next;
};

typedef struct term *expression;
void create_expr(expression *ptrToExpr);
void insertTerm(expression *ptrToExpr , int coeff , int power);
struct term *getFirstTerm(expression *ptrToExpr);
struct term *getNextTerm(struct term *term);
//static void printTerm(struct term *term) ;
void printExpr(expression *ptrToExpr);
void addTerm(expression *prtToExpr, int coeff, int power);
struct term *searchTerm(expression *prtToExpr, int pow);
void makeExprCopy(expression *srcExpr, expression *dstExpr);

