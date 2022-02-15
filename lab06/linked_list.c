#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
   float data;
   struct node *next;
};

void printList(struct node *head) {
    struct node *temp = head;
    struct node *old = temp;
    while(temp!=NULL){
        printf("%f \n-> ",temp -> data);
        old = temp;
        temp = temp->next;
        free(old);
    }
}
struct node *addNode(int x){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct node *head = NULL;
    struct node *temp;
    int a =0;
    srand(time(NULL));
    while (a!= 49){
        temp = addNode(a);
        temp->next = head;
        head=temp; 
        a= rand()%50;
    }
    printList(head);
    printf(" >49< ");
    return 0;
}