#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <memory.h>
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
#define MAXDATASIZE 100
char bufServ[MAXDATASIZE];
/*
--------------------------------------------------------------------------------
|                           HELPING FUNCTIONS                                   |
--------------------------------------------------------------------------------
*/

int checkWin(struct gameboard *game)
{
  printf("checkwin\n");
  // count pieces in order
  int count = 0;
  int i;
  for (i = 0; i < game->size; i++)
  {
    if (game->board[i] == game->col)
    {
      count++;
    }
  }
  return 1;
}

int sendStatus(int sockfd, int status)
{
  int n;
  char buffer[sizeof(int)];
  sprintf(buffer, "%d", status);

  if (send(sockfd, buffer, sizeof(int), 0) == -1)
  {
    fprintf(stderr, "send status to client fail\n");
    return -9;
  }
}

int getStatusServ(int sockfd)
{
  // get status from server
  if (recv(sockfd, bufServ, MAXDATASIZE, 0) == -1)
  {
    perror("recv");
    return -1;
  }
  return atoi(bufServ);
}

// make comma delimited list of board positions to send to client
char *createBoardString(struct gameboard *game, int size)
{
  int i;
  char *boardString = (char *)malloc(sizeof(char) * (size + 1));
  boardString[0] = '\0';
  strcat(boardString, " ");
  for (i = 0; i < size; i++)
  {
    if (i != 0)
    {
      strcat(boardString, ",");
    }
    char *temp = (char *)malloc(sizeof(char) * 2);
    sprintf(temp, "%d", game->board[i]);
    strcat(boardString, temp);
    free(temp);
  }
  printf("%s", boardString);
  return boardString;
}

/*
--------------------------------------------------------------------------------
|                            SEND AND RECIEVE FUNCTIONS                        |
--------------------------------------------------------------------------------
*/

// send row and col to client
void send_row_col(int row, int col, int sockfd)
{
  char buffer[MAXDATASIZE];
  sprintf(buffer, "%d %d ", row, col);
  send(sockfd, buffer, strlen(buffer), 0);
}

// to be implemented
void sendToClient(int sockfd, char *command)
{
  if (send(sockfd, command, strlen(command), 0) == -1)
  {
    fprintf(stderr, "send to client fail.\n");
    exit(1);
  }
  else
  {
    printf("sent serv: %s \n", command);
  }
}

struct gameboard recvBoardServ(int sockfd, struct gameboard *game)
{
  char *buffer = (char *)(malloc(sizeof(char) * MAXDATASIZE));
  memset(buffer, 0, MAXDATASIZE);
  if (recv(sockfd, buffer, MAXDATASIZE, 0) == -1)
  {
    fprintf(stderr, "rcv board server fail.\n");
    exit(1);
  }
  else
  {
    printf("recv board: %s \n", buffer);
  }
  game->col = atoi(strtok(NULL, " "));
  game->row = atoi(strtok(NULL, " "));
  // init gameboard
  int i = 0;
  while (i < game->size)
  {
    game->board[i] = atoi(strtok(NULL, ","));
    i++;
  }
  return *game;
}

// send board to client
void sendBoardServ(int sockfd, struct gameboard *board)
{
  send_row_col(board->row, board->col, sockfd);
  int size = board->size;
  char *boardstring = createBoardString(board, size);
  sendToClient(sockfd, boardstring);
}