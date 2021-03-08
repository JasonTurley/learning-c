/*
 * fork3.c - guess what gets printed on line A
 * 4 Jun 2020
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int global_value = 5;

int main()
{
	pid_t pid;
	int local_value = 5;

	pid = fork();
	if (pid == 0) {		// child
		global_value += 15;
		local_value += 15;
		return 0;
	} else if (pid > 0) {	// parent
		wait(NULL);
		printf("PARENT global_value = %d\n", global_value);
		printf("PARENT local_value = %d\n", local_value);
		return 0;
	}
}
