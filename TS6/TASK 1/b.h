#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	int height;
	int depth;
	struct node *left;
	struct node *right;
};

void initTree();
int hasKey(int key);
void insertKey(int key);
void setHeights();
void setDepths();
void deleteKey(int key);
void printTree();