#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data:
    struct node* next;
};

struct node* head = NULL;

void delatstart()
{
    if(head==NULL)
    {
        printf("The list iis emptu\n");
        return;
    }

    struct node* temp=head;
    head=head->next;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(temp);
}

void delatend()
{
     if(head==NULL)
    {
        printf("The list iis emptu\n");
        return;
    }

    struct node* temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(temp->next->next);
}

void delatposition(int pos)
{
    if(pos<=1 || head==NULL)
    {
        void delatstart();

    }
    struct node* temp=head;
    for(int i=0;i<pos-1 && temp->next!=head ; i++)
    {
        temp=temp->next;
    }
    struct node* delnod=temp->next;
    temp->next=delnod->next;
    free(delnod);
    
    
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

    head->prev=NULL;
    head->data = 1;
    head->next = second;

    second->prev=head;
    second->data = 2;
    second->next = third;

    third->prev=second;
    third->data = 3;
    third->next = fourth;

    fourth->prev=third;
    fourth->data = 4;
    fourth->next = fifth;

    fifth->prev=fourth;
    fifth->data = 5;
    fifth->next = sixth;

    sixth->prev=fifth;
    sixth->data = 6;
    sixth->next = head;


    printf("Original list:\n");
    printList();

    delatstart();
    printf("After deleting at start:\n");
    printList();

    delatend();
    printf("After deleting at end:\n");
    printList();

    delatposition(4);
    printf("After deleting at position 4:\n");
    printList();
}