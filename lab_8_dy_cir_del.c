#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
struct node* tail=NULL;


void delatstart()
{
    
}

void printList()
{
    struct node* temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
}


void main()
{
    struct node* second=NULL;   
    struct node* third=NULL;
    struct node* fourth=NULL;
    struct node* fifth=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));

    head->prev=tail;
    head->data=1;
    head->next=second;

    second->prev=head;
    second->data=2;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=4;
    fourth->next=fifth;

    fifth->prev=fourth;
    fifth->data=5;
    fifth->next=tail;

    tail->prev=fifth;
    tail->data=6;
    tail->next=head;


    printf("Initial list:\n");
    printList();
    printf("\n");
    
    delatstart();
    printf("After inserting 20 at the start:\n");
    printList();
    printf("\n");


    
    delatend();
    printf("After inserting 30 at the end:\n");
    printList();
    printf("\n");


    delanyposition(3);
    printf("After inserting 40 at position 3:\n");
    printList();

}