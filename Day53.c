#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue Node (for BFS)
typedef struct QNode {
    Node* treeNode;
    int hd;
} QNode;

// Create new tree node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* current = queue[front++];

        // Left child
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (!root) return;

    // Queue for BFS
    QNode queue[1000];
    int front = 0, rear = 0;

    // Map: hd -> list of nodes (simple array)
    int map[200][100];   // hd range shifted by +100
    int count[200] = {0};

    int minHD = 0, maxHD = 0;

    queue[rear++] = (QNode){root, 0};

    while (front < rear) {
        QNode temp = queue[front++];
        Node* node = temp.treeNode;
        int hd = temp.hd;

        int index = hd + 100;

        map[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (QNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (QNode){node->right, hd + 1};
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + 100;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}