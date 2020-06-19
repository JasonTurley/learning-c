/*
 * fork2.c - demo fork-exec-wait
 * 4 Jun 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t cpid = fork();
	int wstatus;

	char *path = "/bin/echo";
	char *new_argv[] = {path, "hello", "world", NULL};

	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (cpid == 0) {		// child
		execv(path, new_argv);

		perror("exec");	// exec returns on error only
		exit(EXIT_FAILURE);
	} else {			// parent
		printf("Waiting on my child to finish...\n");
		waitpid(cpid, &wstatus, WUNTRACED);
	}

	return 0;
}
