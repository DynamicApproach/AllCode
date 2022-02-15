// The function in this unit that is called by main():

//     Is responsible for connecting to the server.
//     Once connection with the server is established, you will start the game user interface (suggested to be in a different function in the same unit), which similar to the client in project3:
//         Accepts input from user.
//         Sends corresponding commands to the server for processing.
//         Receives the server's response.
//         Displays result/messages corresponding to the server's response to the command.
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
#include "sp-client-functions.h"

// struct gameboard
// {
//   int *board;
//   int size;
//   int numMoves;
//   int col;
//   int row;
//   int gameOver;
// };

#define MAXDATASIZE 100

struct gameboard gameSetup();
void freeaddrinfo(struct addrinfo *ai);

char *address;
char *port = "3490";
int sockfd, numbytes;
char buf[MAXDATASIZE];
struct addrinfo hints, *servinfo, *p;
int rv;
char s[INET6_ADDRSTRLEN];
char *ping = "Connected";

void *get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET)
  {
    return &(((struct sockaddr_in *)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}
void close_socket(int sockfd, struct addrinfo *servinfo)
{
  close(sockfd);
  freeaddrinfo(servinfo);
}
int startNetworkClient(char *host, char *port)
{

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(host, port, &hints, &servinfo)) != 0)
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
      fprintf(stderr, "client fail.\n");
      continue;
    }
    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
    {
      fprintf(stderr, "connect fail.\n");
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
  printf("client: connecting to %s\n", host); // freezing here?
  printf("TEST CLIENT CONNECT");

  // connected
  return sockfd;
}

void client(char *host, char *port)
{
  int sockfd = startNetworkClient(host, port);
  int col;
  printf("Enter size of first board.\n");
  scanf("%d", &col);
  send(sockfd, &col, sizeof(int), 0);
  // accept host and port and connect to server
  // start game interface
  struct gameboard *board;
  // gameSetup(col); // TODO: fix gamesetup
  //  accept input from user ✔️
  //  send command to server ✔️
  //  receive response from server ✔️
  //  display response to user ✔️
  //  repeat until user quits ✔️

  // connect to the specified address and port

  // send client ready
  int ready = 1;
  send(sockfd, &ready, sizeof(int), 0);
  // handle input from user
  while (1)
  {

    // take user input
    char command;
    printf("What would you like to do?\n");
    scanf("%c", &command);
    // send command to server

    sendToServer(sockfd, &command);
    if (command == 'm') // M P S L N Q
    {
      // move Function
      move(sockfd, board);
    }
    else if (command == 'p' || command == 'P')
    {
      // receive response of board
      recvBoardClient(sockfd, board);

      // display board
      // TODO: fix printing - > fix sending -> only send comma
      //                          limited string with row/col at very start
      printBoardClient(board);
    }
    else if (command == 's' || command == 'S')
    {
      getStatusClient(sockfd);
    }
    else if (command == 'l' || command == 'L')
    {
      getStatusClient(sockfd);
    }
    else if (command == 'n' || command == 'N')
    {
      // get size from user
      int size;
      printf("Enter size of board: ");
      scanf("%d", &size);
      // send size to server
      // convert int to char
      char sizeChar[size];
      sprintf(sizeChar, "%d", size);
      sendToServer(sockfd, sizeChar);
      // receive response of board
      if (getStatusClient(sockfd) == 1)
      {
        recvBoardClient(sockfd, board);
      }
    }
    else if (command == 'q' || command == 'Q')
    {
      exit(1);
    }
    else if (command == 'h' || command == 'H')
    {
      printf("The following commands are available:\n");
      printf("M - Move\n");
      printf("P - Print Board\n");
      printf("S - Save\n");
      printf("L - Load\n");
      printf("N - New Game\n");
      printf("Q - Quit\n");
    }
    else
    {
      printf("Invalid input.\n");
    }

    // receive response from server in each case

    // repeat until user quits
    // close connection
  }
  exit(1);
}
