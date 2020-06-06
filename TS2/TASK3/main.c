#include "deque.c"

int main(void) {
	int i, s;
	init(); // Start deque

	for (i=0; i< 10; i++) {
		insertLeft(i*i);
		//printf("%d %d\n" , left , right);
		s = size();
		printf("Size = %d Data = %d\n", s, removeRight());
		//printf("%d %d\n" , left , right);
		insertLeft(i*i*i);
		//printf("%d %d\n" , left , right);
	}

	while (size()>0) {
		printf("Emptying deque %d\n", removeRight());
	}


	return 0;
}
