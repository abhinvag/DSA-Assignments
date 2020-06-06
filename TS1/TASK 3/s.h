#include <stdlib.h>
#include <stdio.h>

struct node{
	char data;
	struct node *next;
};

extern struct node hdr;

char pull();
void init();
void push(int d);
char peek();
int getp(char d);
void display();