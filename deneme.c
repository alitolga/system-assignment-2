#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>

#define NR_mycall 352

int main(void){
	
	// Showing that system call set_nice_inc is working.
	pid_t pid = getpid();
	printf("pid: %lu\n", pid);
	long y;
	int val = 11;
	y = syscall(NR_mycall, pid, val);
	printf("New nice_inc value of pid: %lu is %ld\n", pid, y);
	
	// Showing that modified fork.c and exit.c codes are working. 
	int f = fork();
	int parentDead = 0;
	
	if (f==0){
		printf("Child\n");
		printf("Child pid is %d\n", getpid());
		printf("Nice value is %d\n", getpriority(PRIO_PROCESS, getpid()) );
	}
	else {
		printf("Parent\n");
		printf("Parent pid is %d\n", getpid());
		printf("Nice value is %d\n", getpriority(PRIO_PROCESS, getpid()) );
		parentDead=1;
	}
	
	return 0;
}
