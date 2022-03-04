#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
// Program to fork and execv "whoami" -

int main(int argc, char* argv[]){

// if no command line argument, print usage
    if (argc == 1){
        printf("Usage: ./main <command>\n");
        exit(1);
    } 
    pid_t x = fork();
    if(x < 0){
        perror("fork error");
        exit(1);
    }
    if(x > 0){
        // parent
        waitpid(-1, &x, 0);
        printf("\n\n--PARENT PROCESS--\n");
        printf(" Parent ID: %d\n", getpid());
        printf(" Child ID: %d\n", x);
        return 0;
    }
    else if(x == 0){
		char *args[4];
		for( int i = 0; i <= argc; i++)
	    {
			if(i == argc)
			{
				args[i] = NULL;
			}else{
				args[i] = argv[i+1];
			}
	    }
            printf("--CHILD PROCESS--\n");
            printf(" Child ID: %d\n", getpid());
            printf(" Parent ID: %d\n\n\n", getppid());
			printf("\nCommand output:\n\n");
            execv(args[0],args);
			exit(0);

    } // which whoami -> ./usr/bin/whoami
}
