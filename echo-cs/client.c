#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#include "utils.h"

#define HOST "127.0.0.1"
#define PORT "6969"
#define DEBUG (0)


void run_client()
{

	char buf[128];
	struct addrinfo hints, *results;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo(HOST, PORT, &hints, &results);

	// create a TCP socket
	int sockfd = socket(results->ai_family, results->ai_socktype, 0);
	if (sockfd < 0) 
		error("socket");

	// connect to the host
	if (connect(sockfd, results->ai_addr, results->ai_addrlen) < 0) 
		error("connect");

	printf("What would you like to say to the server?\n>> ");
	fgets(buf, sizeof(buf), stdin);

	// strip newline char
	buf[strcspn(buf, "\n")] = '\0';

	if (DEBUG) printf("[+] You are about to send %s\n", buf);

	// send message to server
	size_t nbytes = send(sockfd, buf, strlen(buf), 0);
	printf("[+] Sent %s (%ld bytes)\n", buf, nbytes);

	// receive response from server
	recv(sockfd, buf, nbytes, 0);
	printf("[+] Received %s (%ld bytes)\n", buf, nbytes);

	// cleanup
	close(sockfd);

}

int main()
{

	run_client();

	return 0;
}
