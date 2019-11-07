#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 2
#define TIMES 10000

int main(void)
{
	int i;
	volatile int j;
	for(i = 0; i < FORKS; i++)
	{
		if(fork() == 0)
		{
			for(j = 0; j < TIMES; j++)
			{
				printf(10, "%d", j);
			}
			exit();
		}
	}
	for(i = 0; i < FORKS; i++)
	{
		wait();
	}
	exit();
}
