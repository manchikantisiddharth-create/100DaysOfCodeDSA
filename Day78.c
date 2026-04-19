#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1005

int graph[MAX][MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with large values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    bool visited[MAX] = {false};
    int key[MAX];

    // Initialize keys
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; // start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int min = INT_MAX;

        // Pick minimum key vertex not yet visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;
        totalWeight += key[u];

        // Update keys of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}