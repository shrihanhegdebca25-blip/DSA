#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertatstart()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data=10;
   newnode->next=head;
   head=newnode;
}

void insertatend()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=20;
    newnode->next=NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertatposition(int pos)
{
    if(pos == 1) {
        insertatstart();
        return;
    }
    if(head==NULL)
    {
        printf("LIST IS empty\n");
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=15;

    struct node* temp = head;
    for(int i=1 ; i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void printList()
{
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    struct node *second = NULL, *third = NULL, *fourth = NULL, *fifth = NULL, *sixth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    sixth = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

     printf("Original list:\n");
    printList();

    insertatstart();
    printf("After inserting at start:\n");
    printList();

    insertatend();
    printf("After inserting at end:\n");
    printList();

    insertatposition(5);
    printf("After inserting at position 5:\n");
    printList();

}