#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
#include "include/linux/syscalls.h"
#include <linux/kernel.h>
//#include <linux/sched.h> 	// find_task_by_vpid
*/

#define NR_mycall 352

int main(void){
	pid_t pid = getpid();
	printf("pid: %lu\n", pid);
	long y;
	int val = 10;
	y = syscall(NR_mycall, pid, val);
	printf("%ld\n", y);
	
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
