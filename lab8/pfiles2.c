#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#include <stdlib.h>
FILE *fd;
int main()
{
    /*
        Looks in the current directory for files that match the pattern numbers_XXXX.txt.
        For each file, open the file and read the file. You can assume that the file will contain 100 integers.
        Recalculate the sum of the integers.
        Print the filename and the sum of the integers.
        Commit your pfiles2.c file.
    */
    int a[100];
    int count =0;
    int temp=0;
    //numbers_XXXX.txt

    DIR *dirptr;
    struct dirent *dp;

  /* Open the specified directory. */
    if ((dirptr = opendir(".")) == NULL) {
        fprintf(stderr, "Could not open directory\n");
        exit(1);
    }

  /* Go through the directory entries and print file names. */
  /* Replace 1 with correct code: you should use appropriate function and store result in dp, also check for output not to be NULL */
    while (dp != NULL) {
        if( dp-> d_name == "numbers_"){        
        fd = open(dp-> d_name ,O_RDONLY | O_CREAT,0664);
        if (!fd) {
            perror("Error"); // code from lecture files
            return 1;
        }
        for(int x=0;x<100;x++){
            count +=  read(fd,a,sizeof(int));
        }
    }

        }
    printf("%d",count);
    close(fd);
    /* close the directory and stop */
    closedir(dirptr);
    return 0;
}
