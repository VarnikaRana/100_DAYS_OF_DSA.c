#include <stdio.h>
#include <stdlib.h>

// Define structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->val && q < root->val)
        return findLCA(root->left, p, q);

    if (p > root->val && q > root->val)
        return findLCA(root->right, p, q);

    return root; // This is the LCA
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->val);

    return 0;
}
