#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

FILE *fp, *fp2;

int * char_to_bin(char C){
	// converts int to binary and sends back binary number
	// as an array of ints
	int *binary = malloc(sizeof(int)*8);
	int i;
	for(i=0;i<8;i++){
		binary[i] = C % 2;
        C = C / 2;
	}
	return binary;
}


int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Usage: %s <Filename>", argv[0]);
		return 1;
	}


	// Open File 1
	// read file with arg name
	fp = fopen( argv[1], "r");
	// Write File 2
	fp2 = fopen("bin.tmp","w");  // Open File


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
	int Count =0;
	// loop and read file, write to file 2 in binary

	while((c = fgetc(fp)) != EOF){
		printf ("\n--------------- new char ---------------\n");
		printf(" Char converted: %c \n",c);
		int *currentbitstring;
		
		// function to call to convert char to binary
		currentbitstring = char_to_bin(c);

		//binary is correct but backwards
		for(int x=7; x>= 0 ;x--){
			fprintf(fp2,"%d",currentbitstring[x]);
		}

		Count++;
		printf("\n\n\n\n");

		for(int x=7;x>=0;x--){
			printf("%d",currentbitstring[x]);
		}

		//printf("current string %s" , *currentbitstring);
		printf ("\n--------------- end current char ---------------\n");
		
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}