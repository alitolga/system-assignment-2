#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>


//#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h> 	// find_task_by_vpid


#define NR_mycall 352

int main(void){
	
	pid_t pid = getpid();
	printf("pid: %lu\n", pid);
	long y;
	int val = 10;
	y = syscall(NR_mycall, pid, val);
	printf("%ld\n", y);
	
	int f = fork();
	
	int parentDead = 0;
	
	if (f==0){
		
		printf("Child\n");
		printf("Child pid is %d\n", getpid());
		printf("Nice value is %d\n", getpriority(PRIO_PROCESS, getpid()) );
		
		//pid_struct = find_get_pid(pid);
		//t = pid_task(pid_struct, PIDTYPE_PID);
		//printf("Nice inc is %d\n", t->nice_inc);
	}
	else {
		printf("Parent\n");
		printf("Parent pid is %d\n", getpid());
		printf("Nice value is %d\n", getpriority(PRIO_PROCESS, getpid()) );
		parentDead=1;
		//pid_struct = find_get_pid(pid);
		//t = pid_task(pid_struct, PIDTYPE_PID);
		//printf("Nice inc is %d\n", t->nice_inc);
		//exit(0);
	}
	
	
	/*	
	struct pid *pid_struct;
	struct task_struct *t;
	pid_struct = find_get_pid(pid);
	t = pid_task(pid_struct, PIDTYPE_PID);
	//t = find_task_by_vpid(pid);
	printf("%d\n", (t->nice_inc) );
	*/
	
	return 0;
}
