#include "queue.h"
#define SIZE 100001

int front =-1 , rear = -1;
int q[SIZE];


void init(){
    front = -1;
    rear = -1;
}

void insertLeft(int d){
    int s = size();
    if(s==SIZE){
        printf("full queue");
        return;
    }
    if(rear==-1){
        front=rear=0;
        q[rear] = d;
    }
    else{
        rear=(rear+1)%SIZE;
        q[rear]=d;
    }
}

int removeRight(){
    int d,s=size();
    if(front==-1){
        printf("empty queue");
        return -1;
    }
    else{
        d=q[front];
        if(front==rear){
            front=rear=-1;
            return d;
        }
        front=(front+1)%SIZE;
        return d;
    }
}

int size(){
    if(rear==-1){
        return 0;
    }
    else{
        return (SIZE-front+rear)%SIZE+1;
    }
}

int peek(){
    return q[front];
}
