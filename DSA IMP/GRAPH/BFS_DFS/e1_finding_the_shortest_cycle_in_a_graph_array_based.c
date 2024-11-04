#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 5       // Maximum number of vertices
#define INF INT_MAX // Infinite value to represent no connection

// Helper function for Dijkstra's approach: Finds the vertex with minimum distance
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to find the shortest cycle using the Bellman-Ford approach
int findShortestCycleBellmanFord(int graph[MAX][MAX], int V) {
    int shortestCycle = INF;

    // Attempt each vertex as a starting point
    for (int start = 0; start < V; start++) {
        int dist[MAX];

        // Initialize distances to INF
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }

        // Check for cycles returning to the start vertex
        for (int u = 0; u < V; u++) {
            if (graph[u][start] != INF && dist[u] != INF) {
                int cycleLength = dist[u] + graph[u][start];
                if (cycleLength < shortestCycle) {
                    shortestCycle = cycleLength;
                }
            }
        }
    }

    return shortestCycle == INF ? -1 : shortestCycle;
}

// Function to find the shortest cycle using Dijkstra's approach
int findShortestCycleDijkstra(int graph[MAX][MAX], int V) {
    int shortestCycle = INF;

    // Run Dijkstra’s algorithm from each vertex as the starting point
    for (int start = 0; start < V; start++) {
        int dist[MAX];
        bool visited[MAX] = { false };

        // Initialize distances to INF
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;

        // Dijkstra’s algorithm for shortest path
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited, V);
            visited[u] = true;

            // Update distances to adjacent vertices
            for (int v = 0; v < V; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        // Check for cycles returning to the start vertex
        for (int v = 0; v < V; v++) {
            if (graph[v][start] != INF && dist[v] != INF) {
                int cycleLength = dist[v] + graph[v][start];
                if (cycleLength < shortestCycle) {
                    shortestCycle = cycleLength;
                }
            }
        }
    }

    return shortestCycle == INF ? -1 : shortestCycle;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int graph[MAX][MAX];

    // Initialize the graph with INF to represent no edge
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }

    // Input edges and their weights
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }

    // Find and print the shortest cycle using both approaches
    int resultBellmanFord = findShortestCycleBellmanFord(graph, V);
    int resultDijkstra = findShortestCycleDijkstra(graph, V);

    // Print results
    printf("Shortest cycle length using Bellman-Ford: %d\n", resultBellmanFord == -1 ? -1 : resultBellmanFord);
    printf("Shortest cycle length using Dijkstra: %d\n", resultDijkstra == -1 ? -1 : resultDijkstra);

    return 0;
}
