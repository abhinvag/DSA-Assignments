#include <stdio.h>
#include <stdlib.h>
#include "expr.c"

expression expr1;
expression expr2;
expression result;
struct term *term1P, *term2P;

int main(void) {
/* Construct expression 1 */
	create_expr(&expr1); // Get the start pointer set
	insertTerm(&expr1, 10, 1000);
	insertTerm(&expr1, 100, 2000);
	insertTerm(&expr1, -10, 500);
	insertTerm(&expr1, -10, -1000);
	printf("Expression_1 = ");
	printExpr(&expr1);
	create_expr(&result);
	makeExprCopy(&expr1 , &result);
	addTerm(&result, 10, 1000);
	addTerm(&result, 200, 3000);
	addTerm(&result, 110, 500);
	addTerm(&result, 1000, 0);
	addTerm(&result, 10, -1000);
	printf("\nExpression_1 + Expression_2 = ");
	printExpr(&result);
	printf("\n");
	//printf("Expression_1 - Expression_2 = 0\n");
	return 0;
}

