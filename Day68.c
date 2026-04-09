//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];
int in_degree[MAX];
int queue[MAX], front = 0, rear = -1;
// Function to perform Kahn's Algorithm for topological sorting
void kahn(int n) {  
    // Calculate in-degrees
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                in_degree[j]++;
            }
        }
    }
    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }
    printf("Topological Order:\n");
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i]) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
}
int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    // Initialize graph and in-degree array
    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed graph
    }
    kahn(n);
    return 0;
}