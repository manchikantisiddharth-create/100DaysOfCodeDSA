//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <limits.h> 
#define MAX 100 
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int min_dist = INT_MAX, min_index;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_index = v;
            }
        }
        visited[min_index] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[min_index][v] && dist[min_index] != INT_MAX && dist[min_index] + graph[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }
}
int main() {
    int n, e, src;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // directed graph with weight
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(n, src);
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