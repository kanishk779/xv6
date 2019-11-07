#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 2
#define	TIMES 10000

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
			exit();
		}
	}
	int wait_time,run_time;

	for(i = 0; i < FORKS; i++)
	{
		int pid = waitx(&wait_time,&run_time);
		printf(1, "[WAITX] pid[%d] wait time[%d] run time [%d]\n",pid,wait_time,run_time);
	}
	exit();
}
