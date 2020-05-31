/*
 * open.c - demo for opening a file.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	// close()

int main()
{
	int fd1, fd2;

	fd1 = open("test.txt", O_CREAT);  // creates a file with the sticky bit set
	fd2 = open("test2.txt", O_CREAT, 0644);

	close(fd1);
	close(fd2);

	return 0;
}

