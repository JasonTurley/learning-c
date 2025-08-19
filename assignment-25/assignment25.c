#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("./test.txt", O_CREAT | O_RDWR, S_IRWXU);

	if (fd < 0) {
		perror("open");
		return -1;
	}

	printf("Successfully opened a file!\n");
	write(fd, "cool kids only\n", 15);

	return 0;
}
