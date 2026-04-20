#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int n, int graph[MAX][MAX], int source) {
    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // Remove if directed graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, graph, source);

    return 0;
}