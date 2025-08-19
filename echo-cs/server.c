#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#include "utils.h"

#define HOST "127.0.0.1"
#define PORT "6969"
#define MAX_CONNECTIONS (10)

void *connection_handler(void *client_fd);

void run_server()
{
	struct addrinfo hints, *results;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo(HOST, PORT, &hints, &results);

	int sockfd = socket(results->ai_family, results->ai_socktype, 0);
	if (sockfd < 0) 
		error("socket");

	if (bind(sockfd, results->ai_addr, results->ai_addrlen) < 0)
		error("bind");

	if (listen(sockfd, MAX_CONNECTIONS) < 0)
		error("listen");

	printf("[+] Server listening on %s:%s\n", HOST, PORT);
	
	struct sockaddr_storage client_addr;
	socklen_t addr_size = sizeof(client_addr);

	// Main server loop
	while (1) {

		int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
		if (clientfd < 0) {
			fprintf(stderr, "Failed to accept a client\n");
			//continue
		}
		
		pthread_t thread_id = clientfd - sockfd;
		printf("Accepted connection from client %ld\n", thread_id);

		// 
		if (pthread_create(&thread_id, NULL, connection_handler, (void *)&clientfd) < 0) {
			fprintf(stderr, "Could not create thread id %ld\n", thread_id);
			continue;
		}

		// Wait for the threads to join before exiting main thread
		pthread_join(thread_id, NULL);

		close(clientfd);
		printf("Client %ld closed\n", thread_id);
	}

	// close the socket once we are done
	close(sockfd);


}

/* 
 * Echos the message received from a client
 */
void *connection_handler(void *client_fd)
{
	int clientfd = *(int *)client_fd;

	char buf[128];

	// read the client's message
	int nbytes = recv(clientfd, buf, sizeof(buf), 0);
	if (nbytes < 0) {
		perror("recv");
	}

	// write the message back to the client
	send(clientfd, buf, strlen(buf), 0);

	return NULL;
}

int main()
{
	run_server();

	return 0;
}
