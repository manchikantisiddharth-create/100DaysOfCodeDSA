#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];  // adjacency matrix
bool visited[MAX];

// DFS function to detect cycle
bool dfs(int v, int parent, int n) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {  // if there is an edge
            if (!visited[i]) {
                if (dfs(i, v, n))
                    return true;
            } 
            else if (i != parent) {
                return true;  // cycle found
            }
        }
    }
    return false;
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
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}