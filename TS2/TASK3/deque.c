/* An implementation of Deque  */

#define SIZE 10
#define ERR_DATA (-302031)
#include "deque.h"


int data[SIZE];
int left = 0;
int right = 0;

void insertLeft(int d){
	if (size() == SIZE-1){
		return;
	}
	if (left==0&&right==0) {
		data[left]= d;
        left=SIZE-1;
        right=1;
		return;
	}
	data[left] = d;
	left = (left-1+SIZE)%SIZE;

}

void insertRight(int d) {
    if(size() == SIZE-1){
        return;
    }
    data[right]=d;
    right = right+1;
}

int removeLeft() {
    int d,s;
    s=size();
    if(s==0){
        return ERR_DATA;
    }
    left = (left+1)%SIZE;
	d=data[left];
    if (s==1){
        init();
    }
    return d;

}

int removeRight() {
	int d, s;
	s = size();
	/*if (s==0)
		return ERR_DATA;*/ // Error value
	right = (right - 1 + SIZE)%SIZE;
	d = data[right];
	if (s==1){
		init();
	}
	return d;
}

int canWelcome() {
	return size() < SIZE;
}

int isEmpty() {
	return size() == 0;
}

void init() {
	left = right = 0;
}

int size() {
	if (left == 0&&right==0){
		return 0;
	}
	else{
        if(left==right){
            return SIZE-1;
        }
        else if(right-left==1){
            return SIZE;
        }

        else{
            return (right+SIZE-left)%SIZE-1;
        }
	}
}

