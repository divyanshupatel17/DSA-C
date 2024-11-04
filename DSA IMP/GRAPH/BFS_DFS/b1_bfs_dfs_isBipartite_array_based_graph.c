#include <stdio.h>

#define MAX 6

// Function to check if the graph is bipartite using BFS
int isBipartiteBFS(int graph[MAX][MAX], int v, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, which means "uncolored"
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;

    // Process nodes in the queue
    while (front < rear) {
        int u = queue[front++];

        // Check for a self-loop
        if (graph[u][u] == 1) return 0;

        // Explore all adjacent vertices
        for (int adj = 0; adj < v; adj++) {
            if (graph[u][adj] == 1) {  // There is an edge
                if (color[adj] == -1) {  // If the adjacent vertex is not colored
                    color[adj] = 1 - color[u];  // Assign opposite color
                    queue[rear++] = adj;
                } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
                    return 0;  // Graph is not bipartite
                }
            }
        }
    }
    return 1;  // Graph is bipartite
}

// Helper function for DFS
int dfsCheck(int graph[MAX][MAX], int color[], int u, int v) {
    // Explore all adjacent vertices
    for (int adj = 0; adj < v; adj++) {
        if (graph[u][adj] == 1) {  // There is an edge
            if (color[adj] == -1) {  // If the adjacent vertex is not colored
                color[adj] = 1 - color[u];  // Assign opposite color
                if (!dfsCheck(graph, color, adj, v)) {
                    return 0;  // Graph is not bipartite
                }
            } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
                return 0;  // Graph is not bipartite
            }
        }
    }
    return 1;  // Continue checking
}

// Function to check if the graph is bipartite using DFS
int isBipartiteDFS(int graph[MAX][MAX], int v, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, meaning "uncolored"
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    return dfsCheck(graph, color, start, v);
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    // Check if the graph is bipartite using BFS
    if (isBipartiteBFS(graph, v, start)) {
        printf("Yes, the given graph is Bipartite (BFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (BFS check)\n");
    }

    // Check if the graph is bipartite using DFS
    if (isBipartiteDFS(graph, v, start)) {
        printf("Yes, the given graph is Bipartite (DFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (DFS check)\n");
    }

    return 0;
}
