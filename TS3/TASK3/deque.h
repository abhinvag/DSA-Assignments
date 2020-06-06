#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	char data;
	struct node *nextL;
	struct node *nextR;
};

/* Defiend in some othert file */
extern struct node hdr;

/* ADT interface functions */
void init();

void joinL(char d);
void joinR(char d);

char leaveL();
char leaveR();

int size();

