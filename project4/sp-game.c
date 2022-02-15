// Move all game logic(data structures and functions) to this separate unit.The goal is to make the project even more modular than project3 by separating the client - server connection /
// communication from the pure game logic functions(initializing boards, move, etc.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sp-game.h"

int *boardyClient = NULL;
int gameOver;
int crow;
int ccol;

// ALL Functions are defined in sp-game.c

// struct gameboard
// {
// 	int *board;
// 	int size;
// 	int numMoves;
// 	int col;
// 	int row;
// 	int gameOver;
// };

/*
 * Checks location of a number in tiles and give tile locations back
 * @param *r: row to recieve
 * @param *c: column to recieve
 * @param numToFind: input
 * @return : gameboard locations are in (*r, *c)
 */
int map(int *r, int *c, int numToFind, struct gameboard *gb)
{
	int i, j;
	for (i = 0; i < gb->row; i++)
	{
		for (j = 0; j < gb->col; j++)
		{
			if (gb->board[i * gb->size + j] == numToFind)
			{
				*r = i;
				*c = j;
				return 1;
			}
		}
	}
	return -1;
}

void setSlot(int x, int y, int set, struct gameboard *board)
{
	// catch to make sure we don't go out of bounds
	if (x < 0 || x >= board->size || y < 0 || y >= board->size)
	{
		return;
	}
	board->board[x * board->size + y] = set;
}

int getSlot(int x, int y, struct gameboard *board)
{
	return board->board[x * board->size + y];
}
/*
 * Boxes to be displayed between setups
 */

struct gameboard gameSetup(int col)
{
	// TODO: Get size of board from user
	ccol = col;
	crow = col;
	struct gameboard *board = malloc(sizeof(ccol * crow));
	board->board = malloc(sizeof(int) * ccol * crow);
	board->size = ccol * crow;
	board->numMoves = 0;
	for (int i = 0; i < board->size; i++)
	{
		*(board->board + i) = i;
	}
	return *board;
}

/*
--------------------------------------------------------------------------------
|                            SAVE AND LOAD FUNCTIONS                        |
--------------------------------------------------------------------------------
*/

int loadGame(char filename[100], struct gameboard *board)
{
	FILE *fp;
	int c;
	int x = 0, y = 0;
	fp = fopen(filename, "r");
	if (!fp)
	{
		fprintf(stderr, "Error with file load.\n");
		return -1;
	}
	else
	{
		// TODO: free old board
		while ((c = fgetc(fp)) != EOF)
		{
			if (c == '\n')
			{
				x++;
				y++;
			}
			else
			{
				// set slot to random
				// TODO: check for doubles -- old function?
				setSlot(x, y, c, board);
			}
		}
		fclose(fp);
		return 1;
	}
}
int saveGame(char filename[100], struct gameboard *board)
{
	FILE *fp;
	fp = fopen(filename, "w");
	if (!fp)
	{
		fprintf(stderr, "Error with file load.\n");
		return -1;
	}
	else
	{
		for (int i = 0; i < board->size; i++)
		{
			fprintf(fp, "%d\n", *(board->board + i));
		}
		fclose(fp);
		return 1;
	}
}

/*
--------------------------------------------------------------------------------
|                           MOVE FUNCTIONS                        |
--------------------------------------------------------------------------------
*/
int moves[500][2];
// move
void logMove(int start, int end, struct gameboard *game)
{
	moves[game->numMoves][0] = start;
	moves[game->numMoves][1] = end;
	game->numMoves++;
}

int isValid(int move, struct gameboard *board)
{
	int zeroRow, zeroCol;
	int moveRow, moveCol;
	map(&moveRow, &moveCol, move, board);
	// "Is Move Valid?"
	// takes num convers to col/row, checks if 0 is around that, if so return 1 else return 0}
	map(&zeroRow, &zeroCol, 0, board); // {maps zeroLoc to a row/column number and stores in r/c}
	if (((moveCol - 1) <= zeroCol && zeroCol <= (moveCol + 1)) &&
		((moveRow - 1) <= zeroRow && zeroRow <= (moveRow + 1)))
	{ // c is within 1 and r is within 1
		if ((zeroCol == moveCol && zeroRow == moveRow) || (zeroRow == moveRow + 1 && zeroCol == moveCol + 1) ||
			(zeroRow == moveRow - 1 && zeroCol == moveCol - 1) ||
			(zeroRow == moveRow + 1 && zeroCol == moveCol - 1) ||
			(zeroRow == moveRow - 1 && zeroCol == moveCol + 1))
		{ // {but not equal to current slot and not diag (+-1,+-1)}
			// invalid move
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void swap(int move, struct gameboard *board)
{
	// swap two ints in an array
	int r = 0, c = 0;
	map(&r, &c, move, board);
	int temp = board->board[r * board->col + c];
	board->board[r * board->col + c] = board->board[board->row * board->col + board->col - 1];
	board->board[board->row * board->col + board->col - 1] = temp;
	board->numMoves++;
	logMove(move, board->row * board->col + board->col - 1, board);
	// sprintf((int)(board->board[r * board->col + c]), "%d", board->board[board->row * board->col + board->col - 1]);
	// sprintf((int)(board->board[board->row * board->col + board->col - 1]), "%d", temp);
}