#include <stddef.h>
#include <stdint.h>

#include "lib/printk.h"
#include "lib/string.h"
#include "lib/errors.h"

#include "processes/process.h"
#include "processes/scheduler.h"
#include "processes/waitqueue.h"
#include "processes/waitpid.h"

static int debug=0;

struct wait_queue_t waitpid_wait_queue = {
	NULL
};


int32_t waitpid_done(void) {
	/* Wake anyone waiting for exit */
	if (debug) printk("WAITPID: waking all waiters\n");

	wait_queue_wake(&waitpid_wait_queue);

	return 0;
}

int32_t waitpid(int32_t pid, int32_t *wstatus, int32_t options,
		 struct process_control_block_type *caller) {

	struct process_control_block_type *proc;
	int32_t return_value=0;

	if (debug) printk("WAITPID: Waiting on pid %d\n",pid);

	/* Wait for any child */
	if (pid==-1) {
		proc=process_lookup_child(caller);
		if (proc==NULL) return -ECHILD;
	}
	else if (pid<0) {
		printk("WAITPID: UNSUPPORTED NEGATIVE PID %d\n",pid);
		return -ENODEV;
	}
	else {
		proc=process_lookup(pid);
	}

	if (options==WNOHANG) {
		if (proc->status==PROCESS_STATUS_EXITED) {
			if (wstatus!=NULL) *wstatus=proc->exit_value;
			return_value=proc->pid;
		}
		else {
			return_value=0;
		}
	}
	else {
		while (proc->status!=PROCESS_STATUS_EXITED) {
			wait_queue_add(&waitpid_wait_queue,current_process);
			//schedule();
		}
		if (wstatus!=NULL) *wstatus=proc->exit_value;
		return_value=pid;
		/* Kill the zombie now? */
		/* Reschedule? */
	}

	return return_value;
}


