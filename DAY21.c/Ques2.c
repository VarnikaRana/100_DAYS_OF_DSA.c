//Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertEnd(struct ListNode* head, int data) {
    struct ListNode* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 
}

void display(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct ListNode* head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Linked List: ");
    display(head);

    struct ListNode* mid = middleNode(head);
    if (mid != NULL)
        printf("Middle node value = %d\n", mid->val);

    return 0;
}
