#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DEBUG
FILE *fp, *fp2;

int bin_to_int(int *binary){
	// converts binary array to int
    #ifdef DEBUG
    //recieved:
    for (int k = 0; k < sizeof(binary); k++) {
        printf("%d", binary[k]);
    }
    #endif
	int i =0;
	int num =0;
	int current =7;
	for(i=0;i<8;i++){
		num += binary[i] * pow(2,current);
        current--;
    }
    
    #ifdef DEBUG
    printf("num: %d\n",num);
    #endif

    
	return num;
}

int main(int argc, char** argv) {

    #ifdef DEBUG
    int a[] = {0,0,1,0,0,0,1,1}; // # test
    char y = bin_to_int(a);
    printf("---- SELF TEST #y 00100011   -> %c    \n", y);
    #endif


	if (argc < 2) {
		printf("Usage: %s <Filename>", argv[0]);
	}

	// Open File 1
	// read file with arg name
	fp = fopen( argv[1], "r");
	// Write File 2
	fp2 = fopen("final.txt","w");  // Open File


	// File error handling
	if(fp ==NULL){
	    perror("Error open to read");
	    exit(1);
	}
	if(fp2 == NULL){
		perror("Error open to write");
		exit(1);
	}

	char c;
	int count =0;
    char x;
	// loop and read file, write to file 2 in binary
    int currentbitstring[8] = {0,0,0,0,0,0,0,0};
	while((c = fgetc(fp)) != EOF){
        #ifdef DEBUG
		printf ("\n--------------- new char ---------------\n");
		printf(" Char added: %c \n",c);
        #endif
		if( c == '0'){
			currentbitstring[count] = 0;
		}else if (c == '1'){
			currentbitstring[count] = 1;
		}else if (c == '\n'){
			currentbitstring[count] = 0;
		}else{
			printf("ERROR: char not 0 or 1\n");
		}

		//currentbitstring[count] = c; // add char to currentbitstring

        if(count == 7){ // array is full
            x = (bin_to_int(currentbitstring));
            #ifdef DEBUG
            printf(" Char converted: %c ---- from %d,%d,%d,%d,%d,%d,%d,%d \n", x, currentbitstring[0], currentbitstring[1], currentbitstring[2], currentbitstring[3], currentbitstring[4], currentbitstring[5], currentbitstring[6], currentbitstring[7]);
            #endif
            fprintf(fp2,"%c",x); // write to file
            count = 0; // reset count
            // no need to reset currentbitstring as it is overwritten
         }else{
        	count++; 
		}
        
        #ifdef DEBUG
        printf("\n\n\n\n");
		printf ("\n--------------- end current char ---------------\n");
        #endif
		}
	fclose(fp);
	fclose(fp2);
	return 0;
}