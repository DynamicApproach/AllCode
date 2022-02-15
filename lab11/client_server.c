#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define MAXDATASIZE 100
void freeaddrinfo(struct addrinfo *ai);
char *address;

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in *)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}


// accepts an address and port as optional arguments
int main(int argc, char *argv[])
{
	// if the user specifies an address and port, use those
	if (argc == 3)
	{
		// connect to the specified address and port
		char *port = "5555";
		int sockfd, numbytes;
		char buf[MAXDATASIZE];
		struct addrinfo hints, *servinfo, *p;
		int rv;
		char s[INET6_ADDRSTRLEN];

		address = argv[1];
		port = argv[2];

		memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		if ((rv = getaddrinfo(argv[1], port, &hints, &servinfo)) != 0)
		{
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
			return 1;
		} // servinfo now points to a linked list of 1 or more struct addrinfo structures

		// loop through all the results and connect to the first we can
		for (p = servinfo; p != NULL; p = p->ai_next)
		{
			if ((sockfd = socket(p->ai_family, p->ai_socktype,
								 p->ai_protocol)) == -1)
			{
				perror("client: socket");
				continue;
			}
			if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
			{
				perror("client: connect");
				close(sockfd);
				continue;
			}
			break;
		}
		if (p == NULL)
		{
			fprintf(stderr, "client: failed to connect\n");
			return 2;
		}

		inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
				  s, sizeof s);
		printf("client: connecting to %s\n", s); // freezing here?
		printf("TEST CLIENT CONNECT");

		// send the message to the server
		char *ping = "ping";
		if (send(sockfd, ping, strlen(ping), 0) == -1)
		{
			perror("send");
			exit(1);
		}
		// wait for the server to respond
		while (1)
		{
			if ((numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0)) == -1)
			{
				perror("recv");
				exit(1);
			}
			else
			{

				buf[numbytes] = '\0';
				if ((numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0)) == -1)
				{
					perror("recv");
					exit(1);
				}
				else
				{
					buf[numbytes] = '\0';
					printf("%s\n", buf);
				}
			}
			if (send(sockfd, ping, strlen(ping), 0) == -1)
			{
				perror("send");
				exit(1);
			}
		}
		close(sockfd);
		freeaddrinfo(servinfo);
	}
	else
	{
		// server mode
		struct addrinfo hints, *servinfo, *p;
		int listenfd;
		char *port = "5555";
		// struct sockaddr_storage their_addr; // connector's address information
		// socklen_t sin_size;
		// struct sigaction sa;
		int yes = 1;
		// char s[INET6_ADDRSTRLEN];
		int rv;
		memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE; // use my IP
		if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket");
			exit(1);
		}

		int optval = 1;
		setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

		if ((rv = getaddrinfo(NULL, port, &hints, &servinfo)) != 0)
		{
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
			return 1;
		}

		// print socket address
		printf("server: socket fd is %d\n", listenfd);
		printf("server: port is %s\n", port);


		// loop through all the results and bind to the first we can
		for (p = servinfo; p != NULL; p = p->ai_next)
		{
			if ((listenfd = socket(p->ai_family, p->ai_socktype,
								   p->ai_protocol)) == -1)
			{
				perror("server: socket");
				continue;
			}
			if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &yes,
						   sizeof(int)) == -1)
			{
				perror("setsockopt");
				exit(1);
			}
			if (bind(listenfd, p->ai_addr, p->ai_addrlen) == -1)
			{
				close(listenfd);
				perror("server: bind");
				continue;
			}
			if (listen(listenfd, 10) != 0)
			{
				perror("listen()");
				exit(1);
			}
			// call accept
			int clientfd;
			clientfd = accept(listenfd, NULL, NULL);
			// enter a loop of receive, print what it received, then send a message
			// back to the client
			char buffer[1000];
			char *pong = "pong";
			int len;
			while (1)
			{
				if((len = recv(clientfd, buffer, sizeof(buffer), 0)))
				{
					buffer[len] = '\0';
					printf("%s\n", buffer);
					if (send(clientfd, pong, strlen(pong), 0) == -1)
					{
						perror("send");
						exit(1);
					}
				} else {
					printf("client disconnected\n");
					break;
				}


				buffer[len] = '\0';
				//printf("Read %d chars\n", len);
				printf("%s\n", buffer);

				if (send(clientfd, pong, strlen(pong), 0) == -1)
				{
					perror("no ping :(");
					break;
				}
				else
				{
					
				}
			}
			break;
		}
	}
	return 0;
}