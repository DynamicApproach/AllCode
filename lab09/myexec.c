#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int status;
    int pid;
    pid = fork();
    if (pid == 0) {
        // Child
        execvp(argv[1], &argv[1]);
       
        fprintf(stderr, "Error: %d\n",errno);
        exit(1);
    } 
    else if (pid < 0) {
        // Cancelled - error
        fprintf(stderr, "Error: %d\n", errno);
        exit(0);
    }
    else if(pid =1) {
        // Parent
        wait(&status);
    }else{
        fprintf(stderr, "Error: %d\n", errno);
    }
    return 0;
}