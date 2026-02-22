//Problem: Count the number of nodes in a singly linked list.
// Implement the solution using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Counting nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes in the linked list = %d\n", count);

    return 0;
}