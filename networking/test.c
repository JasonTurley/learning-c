#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int close(int fd);

int main()
{
	printf("CREATING SOCKET!\n");

	int sockfd = socket(AF_UNIX, SOCK_RAW, 0);

	if (sockfd < 0) {
		printf("Error creating socket!\n");
		return -1;
	}

	printf("CLOSING SOCKET!\n");
	close(sockfd);
	return 0;
}
