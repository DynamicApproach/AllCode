#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
  #include <sys/wait.h>
// global pipe
int pipe_fd[2];
int pipe_fd2[2];
int id2;
    int id;
int x = 0;
void pingFunction(){
    for(int i = 0; i <= 100; i++){
        printf("ping: %d\n",x);
        x++;
        write(pipe_fd[1],&x,sizeof(x));
        read(pipe_fd2[0],&x,sizeof(x));
    }
}
void signalHandler(int sig){
    printf("Pong quitting\n");
    exit(0);
}

//set up a signal handler for SIGUSR1 to call signalHandler() when it receives that signal. 
void setUpSignalHandler(){
    struct sigaction sig;
    sig.sa_handler = &signalHandler;
    sig.sa_flags = 0;
    sigaction(SIGUSR1,&sig,NULL);

}

void pongFunction(){
    //loop forever: read from a pipe, print pong-{value}, increment the value and write the value to the other pipe
    setUpSignalHandler();
    int x =0 ;
    while(1){
        read(pipe_fd2[1],&x,sizeof(x));
        printf("pong: %d\n",x);
        x++;
        write(pipe_fd[0],&x,sizeof(x));
    }
}

int main()
{
    
    id = fork();
    if(id ==0){
        
        // child
        pingFunction();
        // wait for ping to finish
       wait(&id);
        
    }else{
        
        id2 = fork();
        
        pongFunction();
        wait(&id);
        kill(id,SIGUSR1);
        wait(&id2);
    }
    //pingFunction();
    //pongFunction();

      return 0;
}