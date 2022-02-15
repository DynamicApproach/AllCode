
// to be implemented

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
#include "sp-client-functions.h"
#define MAXDATASIZE 100

char buf[MAXDATASIZE];
struct gameboard
{
    int *board;
    int size;
    int numMoves;
    int col;
    int row;
    int gameOver;
};
// recv board from server and set slots

/*
--------------------------------------------------------------------------------
|                            BOARD SEND FUNCTIONS                        |
--------------------------------------------------------------------------------
*/
struct gameboard recvBoardClient(int sockfd, struct gameboard *gb)
{

    char *buffer = (char *)(malloc(sizeof(char) * MAXDATASIZE));
    memset(buffer, 0, MAXDATASIZE);
    if (recv(sockfd, buffer, MAXDATASIZE, 0) == -1)
    {
        fprintf(stderr, "recieve game board.\n");
        exit(1);
    }
    else
    {
        printf("recv board: %s \n", buffer);
    }
    gb->col = atoi(strtok(NULL, " "));
    gb->row = atoi(strtok(NULL, " "));
    int i = 0;
    while (i < gb->size)
    {
        gb->board[i] = atoi(strtok(NULL, ","));
        i++;
    }
    return *gb;
}

// make comma delimited list of board positions to send to client
char *createBoardStringClient(struct gameboard *game, int size)
{

    int i;
    char *boardString = (char *)malloc(sizeof(char) * (size + 1));
    boardString[0] = '\0';
    strcat(boardString, ",");
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
    printf("%s\n", boardString);
    return boardString;
}
/*
--------------------------------------------------------------------------------
|                            STATUS FUNCTIONS                        |
--------------------------------------------------------------------------------
*/

int getStatusClient(int sockfd)
{
    // get status from server
    if (recv(sockfd, buf, MAXDATASIZE, 0) == -1)
    {
        fprintf(stderr, " Get Status fail.\n");
        exit(1);
    }
    return atoi(buf);
}

/*
--------------------------------------------------------------------------------make qu
|                            GAME FUNCTIONS                        |
--------------------------------------------------------------------------------
*/

void move(int sockfd, struct gameboard *gb)
{
    // accept input from user
    printf("Enter a number to move: ");
    int moveNum;
    scanf("%d", &moveNum);
    // send move to server
    send(sockfd, &moveNum, sizeof(moveNum), 0);
    int x;
    x = getStatusClient(sockfd);
    if (x == 9)
    {
        printf("You won!\n");
        gb->gameOver = 1;
    }
    else if (x == 1)
    {
        recvBoardClient(sockfd, gb);
    }
    else
    {
        fprintf(stderr, "move fail.\n");
    }
}
/*
--------------------------------------------------------------------------------
|                            SEND AND RECIEVE FUNCTIONS                        |
--------------------------------------------------------------------------------
*/

const int BUFFER_SIZE = 1024;
void sendToServer(int sockfd, char *command)
{
    if (send(sockfd, command, strlen(command), 0) == -1)
    {
        fprintf(stderr, "send to server fail.\n");
        exit(1);
    }
    else
    {
        printf("sent serv: %s to SERV\n", command);
    }
}
char *recvFromServerClient(int sockfd)
{
    char *buffer = (char *)(malloc(sizeof(char) * BUFFER_SIZE));
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1)
    {
        fprintf(stderr, "recv from serv error .\n");
        exit(1);
    }
    else
    {
        printf("recv from serv: %s \n", buffer);
    }

    return buffer;
}

// send row and col to serv
void send_row_colClient(int row, int col, int sockfd)
{
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%d %d ", row, col);
    send(sockfd, buffer, strlen(buffer), 0);
}

// send board to server
int sendBoardClient(int sockfd, struct gameboard board)
{
    char *buffer = (char *)(malloc(sizeof(char) * BUFFER_SIZE));
    send_row_colClient(board.row, board.col, sockfd);
    memset(buffer, 0, BUFFER_SIZE);
    // create board string
    char *x = createBoardStringClient(&board, board.size);
    strcat(buffer, x);
    // send board to server
    sendToServer(sockfd, buffer);
}

/*
--------------------------------------------------------------------------------
|                              PRINT FUNCTIONS                                 |
--------------------------------------------------------------------------------
*/
void printBox(int x)
{
    printf("|   %5.0d   |", x);
}

/*
 * Builds a basic UI to build off of.
 */
void displaySetup(struct gameboard *board)
{
    printf("\n");
    for (int i = 0; i < board->row; i++)
    {
        printf("-------------");
    }
    printf("\n");
}

// Prints the board visually
void displayTheGameState(struct gameboard *board)
{
    printf("Current Board: \n");
    for (int k = 0; k < board->col; k++)
    {
        displaySetup(board);
        for (int l = 0; l < board->row; l++)
        {
            printBox(*(board->board + (l + k)));
        }
    }
}
// Calls all functions to pretty up print
// print board to console
void printBoardClient(struct gameboard *board)
{
    displayTheGameState(board);
}