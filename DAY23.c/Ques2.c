//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;   // move 2 steps

        if (slow == fast) {
            return true;  // cycle detected
        }
    }
    return false; // no cycle
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create nodes
    struct ListNode* head = createNode(1);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(3);
    struct ListNode* fourth = createNode(4);

    // Link nodes: 1 -> 2 -> 3 -> 4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle: 4 -> 2
    fourth->next = second;

    if (hasCycle(head))
        printf("true (Cycle detected)\n");
    else
        printf("false (No cycle)\n");

    return 0;
}