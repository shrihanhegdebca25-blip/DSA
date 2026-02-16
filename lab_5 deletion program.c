#include <stdio.h>
#include <stdlib.h> 
struct Node {
    int data;
    struct Node* next;  
};

struct Node* head = NULL;

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteAtstart()
{
    if(head == NULL)
    {
        printf("Invalid input");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

int main()
{
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Created linked list is: ");
    printList(head); 

    deleteAtstart();

    printf("Created linked list after deletion is: ");
    printList(head); 

    return 0;
}

