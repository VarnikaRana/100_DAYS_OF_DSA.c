//Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. 
// val is the value of the current node, and next is a pointer/reference to the next node. 
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list.
// Assume all nodes in the linked list are 0-indexed.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Get value at index
int get(int index) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (count == index)
            return temp->val;
        temp = temp->next;
        count++;
    }
    return -1; // index invalid
}

// Add at head
void addAtHead(int val) {
    struct Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

// Add at tail
void addAtTail(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Add at index
void addAtIndex(int index, int val) {
    if (index == 0) {
        addAtHead(val);
        return;
    }

    struct Node* temp = head;
    int count = 0;

    while (temp != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        return; // invalid index

    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at index
void deleteAtIndex(int index) {
    if (head == NULL)
        return;

    if (index == 0) {
        struct Node* del = head;
        head = head->next;
        free(del);
        return;
    }

    struct Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
        return; // invalid index

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    addAtHead(10);
    addAtTail(20);
    addAtTail(30);
    addAtIndex(1, 15);   // insert at index 1

    printf("Linked List: ");
    display();

    printf("Value at index 2: %d\n", get(2));

    deleteAtIndex(1);

    printf("After deletion: ");
    display();

    return 0;
}