/*Problem:Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX];
int dist[MAX];
void bellman_ford(int n, int m, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    // Check for negative weight cycles
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("NEGATIVE CYCLE\n");
                return;
            }
        }
    }
}
int main() {
    int n, m, src;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // directed graph with weight
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    bellman_ford(n, m, src);
    printf("Shortest distances from source vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: Unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
    return 0;
}