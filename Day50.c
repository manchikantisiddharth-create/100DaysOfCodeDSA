#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main() {
    int n, x, key;
    struct TreeNode* root = NULL;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertIntoBST(root, x);
    }

    // Display BST (optional)
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Input search key
    printf("Enter value to search: ");
    scanf("%d", &key);

    // Search operation
    struct TreeNode* result = searchBST(root, key);

    // Output result
    if (result != NULL) {
        printf("Value %d found in BST.\n", key);
    } else {
        printf("Value %d not found in BST.\n", key);
    }

    return 0;
}