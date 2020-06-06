#include "queue.c"
#define SIZE 100001



int main(){
    int s,t,i;
    for(i=2;i<SIZE;i++){
        insertLeft(i);
    }
    insertLeft(SIZE);
    while(size()!=1){
        s=removeRight();
        while(peek()!=SIZE){
          t=removeRight();
          if(t%s!=0){
            insertLeft(t);
          }
          else{
            continue;
          }
        }
        removeRight();
        insertLeft(SIZE);
        printf("%d " , s);
    }
}