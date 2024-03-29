#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 10
#define TIMES 150000
// Parent forks two children, waits for them to exit and then finally exits

static unsigned long X = 1;

int my_rand(int seed) {
	unsigned long a = 110351245, c = 12345;
	X = a * X + c;
	return ((unsigned int)(X / 65536) % 32768) % seed + 1;
}

int main(void)
{
	int i, j;
	for(i = 0; i < FORKS; i++)
	{
		if(fork() == 0)
		{
			set_priority(my_rand(uptime()) % 101);
			for(j = 0; j < TIMES; j++)
			{
				j++; j--;
				printf(1,"children\n");
			}
			exit();
		}
	}
	int wait_time,run_time;
	for(i = 0; i < FORKS; i++)
	{
		int pid = waitx(&wait_time, &run_time);
		printf(1,"[CHILD EXITED] pid [%d] wait time [%d] run time [%d]\n", pid, wait_time, run_time);
	}
	exit();
}
