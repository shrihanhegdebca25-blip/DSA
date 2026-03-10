#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void delatstart() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node* temp = head;
    if (head->next == head) {  // Single node case
        head = NULL;
    } else {
        head = head->next;
        // Find the last node
        struct node* last = head;
        while (last->next != temp) {
            last = last->next;
        }
        last->next = head;
    }
    free(temp);
}

void delatend() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (head->next == head) {  // Single node case
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
}

void delatposition(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }
    if (pos == 1) {
        delatstart();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }
    struct node* delnod = temp->next;
    temp->next = delnod->next;
    free(delnod);
}

void printList(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
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
    sixth->next = head;

    printf("Original list:\n");
    printList();

    delatstart();
    printf("After deleting at start:\n");
    printList();

    delatend();
    printf("After deleting at end:\n");
    printList();

    delatposition(3);  // Adjusted to a valid position after deletions
    printf("After deleting at position 3:\n");
    printList();

    return 0;
}