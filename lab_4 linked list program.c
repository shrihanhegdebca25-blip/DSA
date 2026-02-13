#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* fourth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    fourth = (struct node*)malloc(sizeof(struct node));
    fourth->data = 4;
    fourth->next = head;

    struct node* current = fourth;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    
    return 0;
}


