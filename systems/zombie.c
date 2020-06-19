/*
 * zombie.c - forks a child process that ultimately becomes a zombie process
 * that remains in the system for at least 10 seconds.
 * Run this program in the background (using the &) and run the command `ps -l`
 * to determine whether the process is a zombie.
 * kill the zombie with `kill -9 pid`.
 *
 * This programming problem is from Operating System Concepts 9th edition.
 *
 * 5 Jun 2020
 */

 #include <stdio.h>
 #include <sys/types.h>
 #include <unistd.h>

 int main()
 {
	pid_t pid;

	pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	} else if (pid == 0) {	// child
		/* do nothing and become a zombie */
	} else {		// parent
		/* sleep/pause so programmer can run ps -l and kill -9 */
		sleep(20);
	}

	return 0;
 }
