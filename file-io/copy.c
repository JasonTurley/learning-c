/*
 * copy.c - copies contents of one file to another, using syscalls.
 * 2 Jun 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 256

void check_error(int fd)
{
	if (fd < 0) {
		perror("open");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: %s src dest\n", argv[0]);
		exit(1);
	}

	char buffer[N];
	int src, dest;
	int bytes_read;

	src = open(argv[1], O_RDONLY);
	check_error(src);

	dest = open(argv[2], O_CREAT | O_WRONLY | O_APPEND, 0664);
	check_error(dest);

	while ((bytes_read = read(src, buffer, N)) != 0)
		write(dest, buffer, bytes_read);

	return 0;
}
