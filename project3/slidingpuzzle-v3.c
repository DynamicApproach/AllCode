//the part I'm most not sure of
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int startClient();
int startServer();
int pipe_fd[2];

int endServer();

int main(){

    int id = fork();
    if(id ==0){
        //start server?
        startServer();
        printf("server\n");
        
    }else{
        
        int id2 = fork();
        if(id2 == 0){
            //start client?
            startClient();
            printf("client\n");
        }
        //wait till client ends?
        wait(&id2);
        endServer();
    }
    return 0;
}