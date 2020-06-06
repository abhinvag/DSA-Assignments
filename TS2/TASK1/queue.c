#define SIZE 10
#include "queue.h"

int q[SIZE];
int fr,rear;

void init(){
    fr = -1; 
    rear=-1;
}

void insertLeft(int d){
    if(rear==SIZE-1){
        rear=0;
    }
    else if(rear==-1){
        fr=rear=0;
    }
    else{
        rear++;
    }
    q[rear]=d;
    
    return;
    

}

int removeRight(){
    int d,s;

    if(fr==-1){
        return -1;
    }
    else{
        
        if(fr==SIZE){
	       fr=0;
        }
        
        d=q[fr];
        fr=fr+1;
        return d;
    }

}

int size(){
    if(rear==-1){
        return 0;
    }
    else{
        return (rear+SIZE-fr)%SIZE+1;
    }
}

