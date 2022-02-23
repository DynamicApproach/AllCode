#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
// Program to fork and execv "whoami" -

int main(int argc, char* argv[]){

    srand(time(NULL)); // init for rand
    // create new file
    FILE *fp;
    fp = fopen("/tmp/numbers.txt", "w");
    if (fp == NULL){
        printf("Error file\n");
        exit(1);
    }

    
    // pipe -> write nums to file -> execv -> read nums from file

    // -- FILE NUMBER LOGIC --
    int fd[2];
    pipe(fd);
    if (pipe(fd) == -1){
        printf("Error pipe\n");
        exit(1);
    }
     //write to file random numbers
    for (int i = 0; i < 20; i++){
        int num = rand() % 100;
         fprintf(fp, "%d\n", num);
    }
    // close file
    fclose(fp);


    // -- FORK --

    // Create a child process
    printf("forkin..\n");
    close(0); 
    dup(fd[0]);
    close(1);// close std out
    dup(fd[1]); // dup pipe to std out

    pid_t x = fork();
     write(fd[1],"/tmp/numbers.txt", sizeof("/tmp/numbers.txt"));
    if(x < 0){
        perror("fork error");
        exit(1);
    }
    if(x > 0){
        // parent 
       
        //write to pipe file path
        // pipe wait for execv, child reads, opens new file and writes out, then this carries on
        waitpid(-1, &x, 0);
        printf("--PARENT PROCESS--\n");
        printf(" Parent ID: %d\n", getpid());
        printf(" Child ID: %d\n", x);
        return 0;
    }
    else if(x == 0){
            printf("--CHILD PROCESS--\n");
            printf(" Child ID: %d\n", getpid());
            printf(" Parent ID: %d\n\n\n", getppid());

            
            


            // path to consumer file
            char* exe[] = {"/home/pi/Desktop/consumer", NULL};
            execv("/home/pi/Desktop/consumer", exe);
            perror("execv error");
    } // which whoami -> ./usr/bin/whoami
}