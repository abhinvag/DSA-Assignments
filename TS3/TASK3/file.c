#include <stdio.h>
#include <stdlib.h>
#include "deque.c"

int main(){
	FILE *pf;
	char ch,a;
	int mark=0;
	pf = fopen("copiedprogram.c" , "r");
	while(!feof(pf)){
		ch = fgetc(pf);
		if(ch=='{'||ch=='('||ch=='['){
			joinL(ch);
		}
		else if(ch==')'){
			a=leaveL();
			if(a=='('){
				continue;
			}
			else{
				mark=1;
				break;
			}
		}
		else if(ch=='}'){
			a=leaveL();
			if(a=='{'){
				continue;
			}
			else{
				mark=1;
				break;
			}
		}
		else if(ch==']'){
			a=leaveL();
			if(a==']'){
				continue;
			}
			else{
				mark=1;
				break;
			}
		}
	}
	if(mark==0&&size()==0){
		printf("program is well balanced");
	}
	else{
		printf("program is not well balanced");
	}
	fclose(pf);
	return 0;
}
