#include <linux/syscalls.h>
#include <linux/kernel.h>

asmlinkage long set_nice_inc(pid_t pid, int value){

	// Some parts of this code is taken from 
	// https://stackoverflow.com/questions/19480649/how-to-modify-task-struct-in-linux-kernel-3-8-0
	// with the intention of educational and fair use.
	struct pid *pid_struct;
	struct task_struct *p;
	pid_struct = find_get_pid(pid);
	p = pid_task(pid_struct, PIDTYPE_PID);
	p->nice_inc = value;
	return p->nice_inc;
}
