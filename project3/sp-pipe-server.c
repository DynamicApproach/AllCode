#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int status = 0;
int row;
int col;
extern int pipe_fd[2];
int gameOver = 0; // game status
int moveCount = 0;
int moves[500][2]; // Array to store moves. 500 moves max.
int *boardy = NULL;

int getSlot(int k, int l);

void setSlot(int x, int y, int set);

int row = 5;
int col = 5;
FILE *fp;


void readAll() {
    int count = 0;
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            read(pipe_fd[0], &boardy[count], sizeof(boardy[count]));
            count++;
        }
    }
}

void writeAll() {
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            int x = getSlot(k, l);
            write(pipe_fd[1], &x, sizeof(x));
        }
    }
}

// Take start and end moves and store them in array to show later
int logMove(int start, int end) {
    moves[moveCount][0] = start;
    moves[moveCount][1] = end;
    moveCount++;
    return moveCount;
}

/*
* Function to save the game state to a file
*/
void saveGame(char filename[100]) {
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error w file %s");
        status = -1;
        write(pipe_fd[1], &status, sizeof(status));
        return;
    }
    fprintf(fp, "%d\n", row);
    for (int x = 0; x < row; x++)
        for (int i = 0; i < col; i++) {
            int d = getSlot(x, i);
            fprintf(fp, "%d\n", d);
        }
    fclose(fp);
    write(pipe_fd[1], &status, sizeof(status));

}

/*
 * Loads the game from a file
 */
void loadGame(char filename[100]) {
    int c;
    int x = 0;
    printf("Enter a filename + ext\n");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error w file");
        status = -1;
        write(pipe_fd[1], &status, sizeof(status));
        return;
    } else {
        status = 1;
        free(boardy);
        fscanf(fp, "%d", &row);
        col = row;
        boardy = malloc(row * col * sizeof(int *));
        while ((fscanf(fp, "%d", &c)) == 1) {
            if (x < row * col) {
                boardy[x] = c;
                x++;
            }
        }
        fclose(fp);
    }
    write(pipe_fd[1], &status, sizeof(status));
    writeAll();
}

/*
* Counts board numbers to see if they are in order or not
* @return total correct # of in order tiles.
*/
int checkWin() {
    int correct = 0;
    for (int k = 0; k < (row * col); k++) {
        if (boardy[k] < boardy[k + 1]) {
            correct++;
        }
    }
    printf("correct = %d ", correct);
    return correct;
}

/*
* Checks location of a number in tiles and give tile locations back
* @param *r: row to recieve
* @param *c: column to recieve
* @param numToFind: input
* @return : gameboard locations are in (*r, *c)
*/
int map(int *r, int *c, int numToFind) {
    for (int k = 0; k < row; ++k) {
        for (int l = 0; l < col; ++l) {
            if (getSlot(k, l) == numToFind) {
                *r = k;
                *c = l;
                return 1;
            }
        }
    }
    return -1;
}

/*
* Ends the game
*/
int endServer() {
    printf("Ending the Game.\n");
    free(boardy);
    return 0;
}

/*
* Function to move empty tile around - takes two locations and swaps them
* @param x: row of num1
* @param y: col of num1
* @param r: row of num2
* @param c: col of num2
* @param board: the game board
*/
void swap(int x, int y, int r, int c) {
    int temp = getSlot(x, y);
    int temp2 = getSlot(r, c);
    setSlot(x, y, temp2);
    setSlot(r, c, temp);
}

/*
* Checks whether a tile can be moved
// @Param r: row of num passed
// @Param c: column of num passed
* @return 1 if tile is movable, and 0 if not.
*/
int zeroRow = 0, zeroCol = 0;

int isValid(int r, int c) { // "Is Move Valid?"
    //{} takes row column and array, checks if 0 is around that, if so return 1 else return 0}
    map(&zeroRow, &zeroCol, 0); // {maps zeroLoc to a row/column number and stores in r/c}
    if (((c - 1) <= zeroCol && zeroCol <= (c + 1)) &&
        ((r - 1) <= zeroRow && zeroRow <= (r + 1))) {// c is within 1 and r is within 1
        if ((zeroCol == c && zeroRow == r) || (zeroRow == r + 1 && zeroCol == c + 1) ||
            (zeroRow == r - 1 && zeroCol == c - 1) ||
            (zeroRow == r + 1 && zeroCol == c - 1) ||
            (zeroRow == r - 1 && zeroCol == c + 1)) { // {but not equal to current slot and not diag (+-1,+-1)}
            //invalid move
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

/*
* Takes a number input, if it is valid sends to swap else sends back to ask for new move
* @param input: number to swap blank with
* {Takes a number input, outputs to map to get a location, store and send the location to isValid, if it is valid sends to swap else sends back to ask for new move}
*/
int moveCommand(int input) { // "Move Tile"
    int c, r, x, y;
    map(&x, &y, 0);
    map(&r, &c, input);
    if (isValid(r, c) == 1) {
        logMove((zeroRow + zeroCol), (r + c));
        swap(x, y, r, c);
        if (checkWin() == ((row * col) - 1)) {
            printf("Congratulations, you won!\n");
            gameOver = 1;
            //printMoves();
        }
        return 1;
    } else {
        return 0;
    }
}

void setSlot(int x, int y, int set) {
    *(boardy + (col * x) + y) = set;
}

int getSlot(int x, int y) {
    return *(boardy + (col * x) + y);
}

// init main game board
// Fill slows with numnbers
void initialization() {
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }
    read(pipe_fd[0], &row, sizeof(int));
    col = row;
    int count = 0;
    boardy = malloc(row * col * sizeof(int *));
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            setSlot(k, l, count++);
            write(pipe_fd[1], &count, sizeof(count));
        }
    }

}

/*
* Takes a number input, find the location and returns a bool
* @param x: int to find
*/
int isThere(int x) {
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            if (getSlot(k, l) == x) {
                return 1;
            }
        }
    }
    return -1;
}

/*
* Sets up the game board to a new board with random numbers
* @param boady: memory location of the game board
*/
int *reinit(int *boardy) {
    boardy = malloc(row * col * sizeof(int *));
    setSlot(rand() % row, rand() % col, 0);
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            int x = 5;
            while (isThere(x) == 1) {
                x = ((rand() % (row * col * col)));
            }
            setSlot(k, l, x);
        }
    }
    setSlot(rand() % row, rand() % col, 0);
    return boardy;
}



/*
* Calls init to print
* Begins accepting input
* Takes a character and determines input based on 'm', 'p', or 'q'
*/
int startServer() {
    read(pipe_fd[0], &row, sizeof(int));
    col = row;
    initialization(); // create board and write all nums to pipe
    int temp = 10;
    srand(time(NULL));
    // get input from client
    while (read(pipe_fd[0], &temp, sizeof(temp)) != 0) {
        // first thing every loop write out win status
        writeAll();

        printf("\nWhat would you like to do? \n");

        if (gameOver == 0) {

            if (checkWin() == ((row * col) - 1)) { // start by checking for win
                temp = 'n';
                write(pipe_fd[1], &temp, sizeof(temp));
                free(boardy);
                reinit(boardy);
                checkWin();
            }
            if (temp == 'm') {
                // move
                int d;
                read(pipe_fd[0], &d, sizeof(d)); // if m is read, we need another input
                int moveAccepted = moveCommand(d);
                if (moveAccepted == 1) {
                    write(pipe_fd[1], &moveAccepted, sizeof(moveAccepted));
                    write(pipe_fd[1], &d, sizeof(d));
                } else {
                    temp = 'm';
                    write(pipe_fd[1], &moveAccepted, sizeof(moveAccepted));
                }
            } else if (temp == 'p') {
                // print
                writeAll();
            } else if (temp == 's') {
                char fileName[100];
                read(pipe_fd[0], &fileName, sizeof(fileName));

                saveGame(fileName);

            } else if (temp == 'l') {
                char fileName[100];
                read(pipe_fd[0], &fileName, sizeof(fileName));

                loadGame(fileName);

            } else if (temp == 'n') {
                free(boardy);
                read(pipe_fd[0], &row, sizeof(row)); // if n is read, we need another input
                col = row;
                reinit(boardy);
                writeAll();
            } else if (temp == 'q') {
                endServer();
                break;
            }
        }
    }
    return 0;
}