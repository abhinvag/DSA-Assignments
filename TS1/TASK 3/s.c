#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "s.h"

struct node hdr;

void init(){
	hdr.next=NULL;
}

void push(int d){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	if(hdr.next==NULL){
		hdr.next=newnode;
		//printf("joined\n");
		return;
	}
	struct node *ptr;
	ptr=hdr.next;
	hdr.next=newnode;
	newnode->next=ptr;
	//printf("joined\n");
	return;
}
char peek(){
	return hdr.next->data;
};

char pull(){
	char d;
	d=hdr.next->data;
	/*if(hdr.next==NULL){
		printf("empty\n");
		return -1;
	}
	if(hdr.next->next==NULL){
		printf("hello\n");
		hdr.next=NULL;
	}*/
	struct node *ptr;
	ptr = hdr.next;
	hdr.next=ptr->next;
	free(ptr);
	//printf("removed\n");
	return d;
}

int getp(char d){
	if(d=='+'||d=='-'){
		return 0;
	}
	else if(d=='*'){
		return 1;
	}
	else if(d=='/'){
		return 2;
	}
	else if(d=='%'){
		return 3;
	}
	else{
		return -1;
	}
}

void display(){
	while(hdr.next!=NULL){
		printf("%c " , pull());
	}
}
