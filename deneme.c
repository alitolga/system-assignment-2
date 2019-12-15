#include <stdio.h>
#define NR_mycall 351

int main(void){
	int x1=10,x2=5, y;
	y = syscall(NR_mycall, x1, x2);
	printf("y: %d", y);
	
	return 0;
}
