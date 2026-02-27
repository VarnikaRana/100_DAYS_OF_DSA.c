//Given the head of a singly linked list, the task is to remove a cycle if present.
//A cycle exists when a node's next pointer points back to a previous node, forming a loop. 
//Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter.
//The terminal will print true if a cycle is removed otherwise, it will print false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool detectAndRemoveCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return false;

    slow = head;
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return true;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next->next = head->next->next;

    bool result = detectAndRemoveCycle(head);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    printList(head);

    return 0;
}