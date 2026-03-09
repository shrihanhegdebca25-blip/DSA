#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void delatstart()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node* temp=head;
    head=head->next;
    if(head != NULL) {
        head->prev=NULL;
    }
    free(temp);

}

void delatend()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
       temp->prev->next=NULL;
    
    free(temp);
}

void delatposition(int pos)
{
    if(head==NULL || pos<=0)
    {
        printf("Invalid position or empty list\n");
        return;
    }
    if(pos==1)
    {
        delatstart();
        return;
    }
    struct node* temp=head;
    for(int i=1;i<pos-1 && temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("Position out of range\n");
        return;
    }
     struct node *delnode = temp->next;
     temp->next = delnode->next;
     if(delnode->next != NULL) {
         delnode->next->prev = temp;
     }
     free(delnode);
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
    sixth->next = NULL;


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