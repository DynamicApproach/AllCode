#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int gameOver;
int row;
int col;
int pipe_fd[2];
int *boardy = NULL;
/*
* Boxes to be displayed between setups
*/
void printBox(int x){
    printf("|   %5.0d   |",x);
}
/*
* Builds a basic UI to build off of.
*/
void displaySetup(){
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        printf("-------------");
    }
    printf("\n");
}

void initialization(){
    
    printf("Welcome to the game! Press Q to quit, M to move or P to print! Try and get them in order. N for new board, S to save or L to load a new file. \n");
    printf("Enter a grid size: ");
    scanf("%d",&row);
    col = row;
    write(pipe_fd[0],&row,sizeof(row));
    write(pipe_fd[0],&col,sizeof(col));
    int count=0;
    boardy = malloc(row*col*sizeof(int *));
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            read(pipe_fd[1],&boardy[count],sizeof(boardy[count]));
        }
    }

    //setSlot(3,0,10);
    displayTheGameState();

}

void readAll(){
    int count=0;
    for (int k = 0; k < row; k++) {
        for (int l = 0; l < col; l++) {
            read(pipe_fd[1],&boardy[count],sizeof(boardy[count]));
        }
    }
}

void displayBoard(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",boardy[i*col+j]);
        }
        printf("\n");
    }
}

int main()
{
    initialization();
    int temp = 10;
    srand(time(NULL));
    //input for the game
    while (temp != 'q'){
        if(temp == 10){
            printf("\nWhat would you like to do? \n");}
        if (gameOver == 0) {
            temp = getchar();
            if (temp == 'k') { // start by checking for win condition - k for kill
                temp = 'p';
                printf("Congratulations, you won!\n A new game has been started \n");
            }
            if (temp == 'm') {
                // move
                int d;
                printf("Enter a number to move.\n");
                write(pipe_fd[0],&d,sizeof(d));
                temp = 10;
                readAll();
            } else if (temp == 'p') {
                // print
                displayTheGameState();
                temp = 10;
            }
            else if(temp == 's'){
                saveGame();
            }else if(temp == 'l'){
                loadGame();
            }else if(temp == 'n'){
                free(boardy);
                printf("Enter a size to move.\n");
                scanf("%d", &row);
                col = row;
                reinit(boardy);
            }
            else if (temp == 'q') {
                teardown();
                break;
            }
        }
    }
    return 0;

}