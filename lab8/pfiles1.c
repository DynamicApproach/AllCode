#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
int main()
{
    srand(time(NULL));
    /*
    Creates an array of 100 random integers in the range of 0-99. The program has no input data (it uses standard functions to generate sequence of random numbers).
    The program sums the random numbers and prints the sum.
    It then writes the numbers to a new file using open(), close() and write(). The filename should be: numbers_XXXX.txt where XXXX is the sum of the numbers in the file.
    The program must contain only one function: int main(void)
    Commit your pfiles1.c and numbers_XXXX.txt files.
    */
    int a[100];
    int count =0;
    int temp=0;
    int b=0;
    char buf[100];
    for(int x =0; x<100; x++){
        a[x] =  rand()%100; 
        count += a[x]; 
    }
    
    int fd = open("whynowork.txt", O_WRONLY | O_CREAT,0664);
    if(fd==-1){
        perror("Error");
        exit(1);
    }
    for(int x=0;x<sizeof(a);x++){
        temp =write(fd, a, (size_t)100);
        if(temp ==-1){
            fprintf(stderr,"Error val \n");
            exit(1);
        }
    }

    printf("%d",count);
    close(fd);
    return 0;
}
