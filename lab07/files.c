#include <stdio.h>

FILE *fp;
int main() {
    int *x;

    fp = fopen("test.txt","r");
    char c;
    int count =0;
    while((c = fgetc(fp)) != EOF){
         if((c==32 || c == 9)&& count < 1){
             count++;
             printf("\n");
         }
         else{
             printf("%c",c);
             count =0 ;
         }
        
    } 
    fclose(fp);
    return 0;
}
