/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h> 
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
int hasCycle(Node** adj, int n, int v, int parent, int* visited) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            if (hasCycle(adj, n, temp->vertex, v, visited)) return 1;
        } else if (temp->vertex != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node** adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int cycleExists = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(adj, n, i, -1, visited)) {
                cycleExists = 1;
                break;
            }
        }
    }

    printf(cycleExists ? "YES\n" : "NO\n");
    free(visited);
    return 0;
}
