#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 10
#define TIMES 150000

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
				j++;j--;
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
