#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Rotate list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Make circular list
    temp->next = head;

    k = k % count;  // Handle k > length
    int stepsToNewHead = count - k;

    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL; // Break circle

    return newHead;
}

// Free memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter k (number of rotations): ");
    scanf("%d", &k);

    printf("Original List:\n");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    printList(head);

    freeList(head);
    return 0;
}
