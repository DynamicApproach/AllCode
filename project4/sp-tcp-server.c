// The function in this unit that is called by main()

//     Is responsible for waiting for and establishing TCP connections with clients.
//     Once a client connection is established, you will fork a new child which will be responsible for serving that specific client.
//     The new server's child will then start the game server logic (suggested to be in a different function in the same unit), which similar to the server in project3:
//         Waits for a command to be received from the client.
//         Processes the command (performs game logic).
//         Responds to the client.

// Note that in the above design as your server process forks a new child for each connecting
// client and serves the client in the context of that server child process, it ensures independence of the games among the clients. Therefore, multiple users can connect to the server and play simultaneously.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include "sp-game.h"
#include "sp-server-functions.h"

// struct gameboard
// {
//   int *board;
//   int size;
//   int numMoves;
//   int col;
//   int row;
//   int gameOver;
// };

// ask about h file
// ask about client and serv running same time

// struct gameboard gameSetup();
// int saveGame(char *filename, struct gameboard *game);
// int loadGame(char *filename, struct gameboard *game);
// int isValid(int move, struct gameboard *board);
// void swap(int move, struct gameboard *board);

void serverLoop(int clientfd, struct gameboard *game)
{
	printf("Server loop started\n");
	int clientReady = 0;
	recv(clientfd, &clientReady, sizeof(int), 0);
	printf("%d\n", clientReady);
	// init board and write to client
	// read first ping and write back
	printf("server: accepted connection\n");
	while (1)
	{

		char *command;
		//  client print board
		//  read and wait for command
		recv(clientfd, &command, sizeof(char *), 0);
		printf("server: received command: %s\n", command);
		//  process command
		if (command == "p")
		{
			//  write board to client
			sendBoardServ(clientfd, game); // send row and col then send board string
		}
		else if (command == "m")
		{
			int move = recv(clientfd, &move, sizeof(move), 0);
			printf("server: received move: %d\n", move);
			//  process move
			if (isValid(move, game) == 1)
			{
				swap(move, game);
				// send status
				int win = checkWin(game);
				if (win == ((game->size) - 1))
				{
					sendStatus(clientfd, 9);
					printf("Congratulations, you won!\n");
					game->gameOver = 1;
					// printMoves();
				}
				else
				{
					sendStatus(clientfd, 1);
					sendBoardServ(clientfd, game);
				}
			}
			else
			{
				sendStatus(clientfd, 0);
			}
		}
		else if (command == "s")
		{
			char *filename;
			recv(clientfd, &filename, sizeof(filename), 0);
			printf("server: received move: %s\n", filename);
			//  save board to server
			if (saveGame(filename, game) == 1)
			{
				sendStatus(clientfd, 1);
				printf("Game saved successfully. Saved as %s\n ", filename); // change to write on clientside
			}
			else
			{
				sendStatus(clientfd, -1);
				printf("Error saving game.\n");
			}
		}
		else if (command == "l")
		{
			char *filename;
			recv(clientfd, &filename, sizeof(filename), 0);
			printf("server: received move: %s\n", filename);
			// load board server
			if (loadGame(filename, game) == 1)
			{
				sendStatus(clientfd, 1);
				printf("Game loaded successfully. Opened%s\n", filename); // change to write to client
			}
			else
			{
				sendStatus(clientfd, -1);
				printf("Error loading game.\n");
			}
		}
		else if (command == "n")
		{

			int sizey = recv(clientfd, &sizey, sizeof(sizey), 0);
			printf("server: received size: %d\n", sizey);

			//  resetboard
			game->col = sizey;
			game->gameOver = 0;
			game->numMoves = 0;
			game->board = (int *)malloc(sizey * sizey * sizeof(int));
			for (int i = 0; i < sizey * sizey; i++)
			{
				game->board[i] = i; // TODO: funct to check duplicates
			}
			sendBoardServ(clientfd, game);
			//  write reset to client
		}
		else if (command == "q")
		{
			exit(1);
		}
		else
		{
			printf("server: invalid command\n");
			// How did we get here? Commands should be validated before reaching this point
			//  invalid command
			//  write invalid command to client
		}
	}
}

int serverNetworking(char *port)
{
	printf("serv network hit");
	// server mode
	struct addrinfo hints, *servinfo, *p;
	int listenfd;
	int yes = 1;
	int rv;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	int optval = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	if ((rv = getaddrinfo(NULL, port, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
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
		if (listen(listenfd, 100) != 0)
		{
			perror("listen()");
			exit(1);
		}
	}
	return listenfd;
}

void serveraddr(char *port)
{
	// int serv = serverNetworking(port);
	int pid;
	printf("server:listening\n");
	int clientfd = accept(serverNetworking(port), (struct sockaddr *)NULL, NULL);
	if (clientfd == -1)
	{
		perror("Unable to accept connection");
		exit(1);
	}
	char buffer[256];
	pid = fork();
	if (pid == 0)
	{
		// recieve col/row

		int ccol;
		recv(clientfd, &ccol, sizeof(int), 0);
		struct gameboard board = gameSetup(ccol);
		// child process
		// start loop and wait for client
		serverLoop(clientfd, &board);
	}
	else
	{
		printf("server: waiting for connections\n");
		// close(serv);
	}
	close(clientfd);
	exit(1);
}
void server()
{
	printf("server hit");
	// server no params
	char *portx = "3490";
	serveraddr(portx);
}