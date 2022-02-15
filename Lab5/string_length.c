#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int gameOver;
int row;
int col;
int pipe_fd[2];
int *boardy = NULL;
int safeMove;


void setSlot(int x, int y, int set) {
    *(boardy + (col * x) + y) = set;
}

int getSlot(int x, int y) {
    return *(boardy + (col * x) + y);
}

/*
* Boxes to be displayed between setups
*/
void printBox(int x) {
    printf("|   %5.0d   |", x);
}

/*
* Builds a basic UI to build off of.
*/
void displaySetup() {
    printf("\n");
    for (int i = 0; i < row; i++) {
        printf("-------------");
    }
    printf("\n");
}

void displayTheGameState() {

    printf("Current Board: \n");
    for (int k = 0; k < row; k++) {
        displaySetup();
        for (int l = 0; l < col; l++) {
            printBox(getSlot(k, l));
        }
    }
}

void initialization() {

    printf("Welcome to the game! Press Q to quit, M to move or P to print! Try and get them in order. N for new board, S to save or L to load a new file. \n");
    printf("Enter a grid size: ");
    scanf("%d", &row);
    col = row;
    write(pipe_fd[0], &row, sizeof(row));
    int count = 0;
    boardy = malloc(row * col * sizeof(int *));
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            read(pipe_fd[1], &boardy[count], sizeof(boardy[count]));
        }
    }
    displayTheGameState();

}

void readAll() {
    int count = 0;
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            read(pipe_fd[1], &boardy[count], sizeof(boardy[count]));
            count++;
        }
    }
}

void displayBoard() {
    readAll();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", boardy[i * col + j]);
        }
        printf("\n");
    }
}

int main() {
    initialization();
    int temp = 10;
    srand(time(NULL));
    //input for the game
    while (temp != 'q') {
        // first thing every loop read in win status
        read(pipe_fd[1], &gameOver, sizeof(gameOver));
        if (temp == 10) {
            printf("\nWhat would you like to do? \n");
        }
        if (gameOver == 0) {
            temp = getchar();
            if (temp == 'm') {
                // move
                int d;
                printf("Enter a number to move.\n");
                scanf("%d", &d);
                write(pipe_fd[0], &temp, sizeof(temp)); // writing move command and number to pipe
                write(pipe_fd[0], &d, sizeof(d));
                temp = 10;
                if (read(pipe_fd[1], &safeMove, sizeof(safeMove)) == 1) {
                    readAll();
                    displayTheGameState();
                } else {
                    printf("Invalid move!\n");

                }
            } else if (temp == 'p') {
                // print
                displayTheGameState();
                temp = 10;
            } else if (temp == 's') {
                printf("File name?\n");
                char fileName[100];
                fgetc(fileName);
                write(pipe_fd[0], &temp, sizeof(temp)); // write s to load
                write(pipe_fd[0], &fileName, sizeof(fileName)); // write filename
                read(pipe_fd[1], &temp, sizeof(temp));
                if (temp == 1) {
                    printf("File saved!\n");
                } else {
                    printf("File not saved!\n");
                }
                printf("Game saved!\n");
            } else if (temp == 'l') {
                printf("File name?\n");
                char fileName[100];
                fgetc(fileName);
                write(pipe_fd[0], &temp, sizeof(temp)); // write l to load
                write(pipe_fd[0], &fileName, sizeof(fileName)); // write filename
                read(pipe_fd[1], &temp, sizeof(temp)); // is read if file exists
                if (temp == 1) {
                    readAll();
                    printf("File loaded!\n");
                } else {
                    printf("File not loaded! -- Server error\n");
                }
                printf("Game saved!\n");
            } else if (temp == 'n') {
                free(boardy);
                printf("Enter a size to move.\n");
                scanf("%d", &row);
                col = row;
                reinit(boardy);
            } else if (temp == 'q') {
                teardown();
                break;
            }
        }
    }
    return 0;

}