#include <stdio.h>
#include <stdio.h>
#include "dlink.h"
#include <string.h>

struct chair hdr;
int k=20;
int i;

void init(){
	hdr.leftchair=hdr.rightchair=NULL;
	return;
}

void insertchair(char *ch){
	int count = 0;
	struct chair *newchair = (struct chair*)malloc(sizeof(struct chair));
	newchair->player=ch;
	if(hdr.rightchair==NULL){
		hdr.rightchair=newchair;
		hdr.leftchair=newchair;
		newchair->leftchair = newchair->rightchair = NULL;
		//printf("first node inserted\n");
		return;
	}
	hdr.rightchair->rightchair=newchair;
	newchair->leftchair=hdr.rightchair;
	newchair->rightchair=hdr.leftchair;
	hdr.rightchair=newchair;
	hdr.leftchair->leftchair=newchair;
	printf("Player inserted %s\n" , ch);
	return;
}

int isempty(){
	if(k==0){
		return -1;
	}
	return 0;
}

char *whoinchair(){
	struct chair *ptr;
	ptr = hdr.leftchair;
	return ptr->player;

}

char *removechair(int d){
	if(d<0){
		struct chair *ptr = hdr.leftchair;
		if(d==-1){
			ptr->rightchair->leftchair = hdr.rightchair;
			hdr.rightchair->rightchair = ptr->rightchair;
			hdr.leftchair = ptr->rightchair;
			free(ptr);
			k--;
			//printf("%d\n" , k);
			return ptr->player;
		}
		d = abs(d);
		for(i=1;i<d;i++){
			ptr = ptr->rightchair;
		}
		if(ptr==hdr.rightchair){
			hdr.rightchair = ptr->leftchair;
		}
		if(ptr==hdr.leftchair){
			hdr.leftchair = ptr->rightchair;
		}
		ptr->leftchair->rightchair = ptr->rightchair;
		ptr->rightchair->leftchair=ptr->leftchair;
		free(ptr);
		k--;
		//printf("%d\n" , k);
		return ptr->player;
	}
	struct chair *ptr = hdr.rightchair;
	for(i=1;i<d;i++){
		ptr = ptr->leftchair;
	}
	if(ptr==hdr.leftchair){
		hdr.leftchair = ptr->rightchair;
	}
	ptr->leftchair->rightchair = ptr->rightchair;
	ptr->rightchair->leftchair=ptr->leftchair;
	free(ptr);
	k--;
	//printf("%d\n" , k);
	return ptr->player;

}