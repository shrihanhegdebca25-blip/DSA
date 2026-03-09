#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// global head used by manipulation functions
struct node *head = NULL;

void delatstart()
{
    if(head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delatend()
{
    if(head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    struct node *last = temp->next;
    temp->next = NULL;
    free(last);
}

void delatPOS(int pos)
{
    if(head == NULL || pos <= 0) {
        printf("Invalid position or empty list\n");
        return;
    }
    if(pos == 1) {
        delatstart();
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < pos-1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node *delnode = temp->next;
    temp->next = delnode->next;
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

int main()
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

    delatstart();
    printf("After deleting at start:\n");
    printList();

    delatend();
    printf("After deleting at end:\n");
    printList();

    delatPOS(2);
    printf("After deleting position 2:\n");
    printList();

    return 0;
}