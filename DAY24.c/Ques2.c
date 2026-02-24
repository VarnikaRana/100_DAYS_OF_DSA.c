//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head

#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Remove all elements with given value
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove matching nodes from the beginning
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* curr = head;

    // Remove matching nodes from the rest
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

// Display list
void display(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;

    // Create list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 6);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);

    printf("Original List:\n");
    display(head);

    int val = 6;
    head = removeElements(head, val);

    printf("List after removing %d:\n", val);
    display(head);

    return 0;
}