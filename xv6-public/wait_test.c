#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	if(!fork())
	{
		sleep(50);
		exit();
	}
	else
	{
		int status = wait();
		printf(1, "child status = %d\n", status);
	}
}
