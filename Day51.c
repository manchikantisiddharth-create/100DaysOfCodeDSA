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
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val) {
            root = root->left;
        } else if (p > root->val && q > root->val) {
            root = root->right;
        } else {
            return root; // This is the LCA
        }
    }
    return NULL;
}

// Main function
int main() {
    int n, x, p, q;
    struct TreeNode* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertIntoBST(root, x);
    }

    // Input nodes to find LCA
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Output result
    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}