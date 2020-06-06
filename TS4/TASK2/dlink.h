#include <stdio.h>
#include <stdlib.h>

struct chair{
	struct chair *leftchair;
	char *player;
	struct chair *rightchair;
};

//extern struct chair hdr;
void init();
void insertchair(char *ch);
int isempty();
char *whoinchair();
char *removechair(int d);


