/*
 * fork1.c - demo program for creating processes with fork()
 * 4 Jun 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t cpid;

	cpid = fork();
	if (cpid == -1)	{	// error
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {	// child
		printf("I am the child! (%d)\n", getpid());
	} else {		// parent
		printf("I am the parent! (%d)\n", getpid());
	}

	return 0;
}
