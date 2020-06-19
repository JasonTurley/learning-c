/*
 * unlink.c - deletes a name from the file system. If no other processes have
 * the file open, it is deleted and the space is freed.
 * 31 May 2020
 */

#include <stdio.h>
#include <unistd.h>

const char *pathname = "/bin/chmod";

int main()
{
	if (unlink(pathname) == -1) {
		perror("unlink");
		return 1;
	}

	printf("Removed %s\n", pathname);

	return 0;
}
