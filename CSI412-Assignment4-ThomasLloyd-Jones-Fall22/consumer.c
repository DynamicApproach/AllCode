#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    // read from stdin
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // read filepath from stdin

    read = getline(&line, &len, stdin);
    if(read == -1){
        perror("getline error");
        exit(1);
    }

    // open filepath stored in the pipe and read
    FILE *fp = fopen(line, "r");
    // create new file to write to
    FILE *fp2 = fopen("testoutput.txt", "w");
    if(fp2 == NULL || fp == NULL){
        perror("fopen error");
        exit(1);
    }
    int total=0;
    int x=0;
    // read from file line by line
    while((fscanf(fp,"%d", &x)) != EOF){
        if(x %2 == 0){
            fprintf(fp2, "%d\n", x);
        }
        else{
            total += x;
        }

    }

    fprintf(fp2, "odd total: %d\n", total);

    // close file
    fclose(fp);
    // close file 2
    fclose(fp2);
    // free memory
    free(line);
    return 0;
}