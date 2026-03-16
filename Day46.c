//day466
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(&q, curr->left);
        if (curr->right)
            enqueue(&q, curr->right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[1000];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);

    levelOrder(root);
    printf("\n");

    return 0;
}