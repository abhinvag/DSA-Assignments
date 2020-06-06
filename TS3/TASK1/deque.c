
#include "deque.h"

/* storage allocated here */
struct node hdr;

/* ADT interface functions */
/* THink of hdr as if it is on top
of all member nodes of deque.
Left and right of header is not symmetric to
those of member nodes */
void init() {
	// unused
	hdr.data = 0;
	hdr.nextL = hdr.nextR = NULL;
}

void joinL(int d) {
	printf("Going to join %d on left\n", d);
	struct node *new = malloc(sizeof(struct node));
	assert(new!=NULL); // Stop if problem

	new->data = d;

	if (hdr.nextL == NULL) {
		assert(hdr.nextR == NULL);
		hdr.nextL = hdr.nextR = new;
		new->nextL = new->nextR = NULL;
		printf("Joined %d on left\n", d);
		return;
	}
    assert(hdr.nextL != NULL);//
	assert(hdr.nextR != NULL);
	assert(hdr.nextL->nextL == NULL);
	hdr.nextL->nextL = new;
	new->nextR = hdr.nextL;
	new->nextL = NULL;
	hdr.nextL = new;
	printf("Joined %d on left\n", d);
	assert(new->nextL==NULL);//
}

void joinR(int d) {
	printf("Going to join %d on right\n" , d);
	struct node *new = malloc(sizeof(struct node));
	new->data = d;
	if(hdr.nextR==NULL){
        hdr.nextL=hdr.nextR=new;
        new->nextL=new->nextR=NULL;
        printf("joined %d on right\n" , d);
        return;
	}

	hdr.nextR->nextR=new;
	new->nextL=hdr.nextR;
	new->nextR=NULL;
	hdr.nextR=new;
	printf("joined %d on the right\n" , d);
}

int leaveL() {
	struct node *temp;
	printf("Someone is leaving from left\n");
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	int d = hdr.nextL->data;
	temp=hdr.nextL->nextR;
	if(temp!=NULL){
        temp->nextL=NULL;
	}
    free(hdr.nextL);
    hdr.nextL=temp;
    printf("from left %d left\n" , d);
    if(temp==NULL){
        hdr.nextR=NULL;
	}
	assert (temp != NULL || hdr.nextR == NULL);
	return d;
}
int leaveR() {
	struct node *tmp;
	printf("Someone leaving from Right\n");
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	int d = hdr.nextR->data;
	tmp = hdr.nextR->nextL;
	if (tmp != NULL)
		tmp->nextR = NULL;
	free(hdr.nextR);
	hdr.nextR = tmp;
	printf("From right %d left\n", d);
	if (tmp == NULL)
		hdr.nextL = NULL;
	assert (tmp != NULL || hdr.nextL == NULL);
	return d;
}

int size() {
	int i = 0;
	struct node *ptr = hdr.nextL;

	while (ptr != NULL) {
		i++; ptr = ptr->nextR;
	}
	return i;
}
