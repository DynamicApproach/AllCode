//
// Created by lloyd on 9/29/2021.
//
#include <stdio.h>
#include <string.h>
int findLen(char*);

int main()
{
    char a[100] = {"test"};
    printf("Enter a string: ");
    scanf("%s",a);
    printf("Length of string without standard functions: %d \n",findLen(a));
    printf("Length of string with standard functions: %d \n", strnlen(a,100));

    return 0;
}

int findLen(char* b)
{
    int i=0, count=0;
    while(b[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
