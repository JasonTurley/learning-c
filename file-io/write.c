/*
 * write.c - demo for writing to a file
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("myfile", O_CREAT | O_RDWR, 0666);

	write(fd, "hello there!\n", 13);

	close(fd);
}
