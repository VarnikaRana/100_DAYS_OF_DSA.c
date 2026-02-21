//Problem: Create and Traverse Singly Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nLinked List elements are:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
