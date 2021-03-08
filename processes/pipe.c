/*
 * pipe.c - parent process sends a message to child process
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 16
#define READ_END 0
#define WRITE_END 1

int main()
{
	int fd[2];
	pid_t cpid;

	char write_msg[BUF_SIZE] = "Greetings";
	char read_msg[BUF_SIZE];

	pipe(fd);

	cpid = fork();

	if (cpid == -1) {	// error
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {	// child
		// close the unused end of the pipe
		close(fd[WRITE_END]);

		read(fd[READ_END], read_msg, BUF_SIZE);

		close(fd[READ_END]);

		printf("Read %s from parent (%ld)\n", read_msg, (long)getppid());
	} else {		// parent
		// close the unused end of the pipe
		close(fd[READ_END]);

		write(fd[WRITE_END], write_msg, strlen(write_msg)+ 1);

		// important to close the WRITE_END to make sure reader receives
		// end-of-file (read returns 0)
		close(fd[WRITE_END]);
	}

	return 0;
}
