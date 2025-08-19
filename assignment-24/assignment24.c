#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd = open("./test.txt", O_CREAT | O_RDWR, S_IRWXU);

	if (fd < 0) {
		perror("open");
		return -1;
	}

	printf("Successfully opened a file!\n");

	return 0;
}
