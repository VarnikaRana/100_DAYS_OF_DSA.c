//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    struct Node* head2 = createNode(9);
    head2->next = head1->next->next->next; 

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection != NULL)
        printf("Intersection point data = %d\n", intersection->data);
    else
        printf("No intersection point found.\n");

    return 0;
}