struct gameboard
{
  int *board;
  int size;
  int numMoves;
  int col;
  int row;
  int gameOver;
};

struct gameboard gameSetup();
int saveGame(char *filename, struct gameboard *game);
int loadGame(char *filename, struct gameboard *game);
int isValid(int move, struct gameboard *board);
void swap(int move, struct gameboard *board);

int map(int *r, int *c, int numToFind, struct gameboard *gb);
int isValid(int move, struct gameboard *gb);
void swap(int move, struct gameboard *gb);