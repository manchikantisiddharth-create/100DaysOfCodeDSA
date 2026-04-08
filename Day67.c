#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int stack[MAX], top = -1;

// DFS function
void dfs(int v, int n) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    stack[++top] = v; // push after visiting all neighbors
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed graph
    }

    // call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, n);
    }

    // print topological order (reverse of stack)
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}