#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertatstart(int value)
{
    struct node *newnode = malloc(sizeof *newnode);
    newnode->data = value;
    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }


    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void insertatend(int value)
{
    struct node *newnode = malloc(sizeof *newnode);
    newnode->data = value;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
      {
         temp = temp->next;
      }
    temp->next = newnode;
    newnode->next = head;
}

void insertatposition(int pos, int value)
{
    if (pos <= 1 || head == NULL) {      /* insert at start */
        insertatstart(value);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; ++i)
    {
        temp = temp->next;
    }

    struct node *newnode = malloc(sizeof *newnode);
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void printList(void)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main(void)
{
    struct node *second, *third, *fourth, *fifth, *sixth;

    head   = malloc(sizeof *head);
    second = malloc(sizeof *second);
    third  = malloc(sizeof *third);
    fourth = malloc(sizeof *fourth);
    fifth  = malloc(sizeof *fifth);
    sixth  = malloc(sizeof *sixth);

    head->data   = 1; head->next   = second;
    second->data = 2; second->next = third;
    third->data  = 3; third->next  = fourth;
    fourth->data = 4; fourth->next = fifth;
    fifth->data  = 5; fifth->next  = sixth;
    sixth->data  = 6; sixth->next  = head;
    
    printf("Initial list:\n");
    printList();
    insertatstart(14);
    printf("After inserting 14 at the start:\n");
    printList();
    insertatend(12);
    printf("After inserting 12 at the end:\n");
    printList();
    printf("After inserting 99 at position 4:\n");
    insertatposition(4, 99);
    printList();

    return 0;
}