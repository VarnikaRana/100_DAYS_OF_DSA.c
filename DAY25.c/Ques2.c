//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
//Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         
        fast = fast->next->next;   

        if (slow == fast)
            return true;          
    }

    return false;                  // no cycle
}

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct ListNode *head = NULL, *tail = NULL;
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct ListNode* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    // Create cycle if pos != -1
    if (pos != -1) {
        struct ListNode *temp = head;
        int count = 0;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp != NULL) {
            tail->next = temp; // create cycle
        }
    }

    if (hasCycle(head))
        printf("Cycle detected in the linked list.\n");
    else
        printf("No cycle in the linked list.\n");

    return 0;
}