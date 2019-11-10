#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 2
#define	TIMES 10000

struct proc_stat { 
	int pid;   // PID of each process  
	float runtime;  // Use suitable unit of time 
	int num_run; // number of time the process is executed 
	int current_queue; // current assigned queue 
	int ticks[5]; // number of ticks each process has received at each of the 5  priority 
};


// Parent forks two children, waits for them to exit and then finally exits
int main(void)
{
	int i,j;
	int myVar = 1;
	for(i=0;i<FORKS;i++)
	{
		if(fork() == 0)
		{
			for(j=0;j<TIMES;j++)
			{
				j++; j--;
				printf(5,"hello\n");
				myVar *= 2;
				myVar /= 2;
			}
			struct proc_stat p;
			getpinfo(&p);
			printf(1, "[GETPINFO] ");
			printf(1, "pid[%d] ", p.pid);
			printf(1, "num_run[%d] ", p.num_run);
			printf(1, "current_queue[%d] ", p.current_queue);
			int k;
			for(k= 0; k < 5; k++)
			{
				printf(1, "ticks[%d] = (%d) ", k, p.ticks[k]);
			}
			exit();
		}
	}
	int wait_time,run_time;

	for(i = 0; i < FORKS; i++)
	{
		waitx(&wait_time,&run_time);
	}
	exit();
}
