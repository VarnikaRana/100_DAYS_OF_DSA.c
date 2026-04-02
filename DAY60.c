#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* queue[SIZE];
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        // Right child
        if (i < n) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Check Complete Binary Tree
int isComplete(struct Node* root) {
    struct Node* queue[SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int flag = 0;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr == NULL) {
            flag = 1;
        } else {
            if (flag) return 0;

            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }

    return 1;
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (root == NULL) return 1;

    if (root->left && root->data > root->left->data)
        return 0;

    if (root->right && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    if (isComplete(root) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
