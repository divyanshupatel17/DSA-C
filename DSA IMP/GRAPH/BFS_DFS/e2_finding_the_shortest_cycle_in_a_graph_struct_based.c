#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 5       // Maximum number of vertices
#define INF INT_MAX // Infinite value to represent no connection

// Graph structure
typedef struct {
    int adj[MAX][MAX]; // Adjacency matrix
    int V;             // Number of vertices
} Graph;

// Initializes graph by setting edges to INF (no connection)
void initGraph(Graph* g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = INF;
        }
    }
}

// Helper function: Finds the vertex with minimum distance for Dijkstra
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

// Finds the shortest cycle using Bellman-Ford
int findShortestCycleBellmanFord(Graph* g) {
    int shortestCycle = INF;

    for (int start = 0; start < g->V; start++) {
        int dist[MAX];
        for (int i = 0; i < g->V; i++) dist[i] = INF;  // Initialize distances
        dist[start] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < g->V - 1; i++) {
            for (int u = 0; u < g->V; u++) {
                for (int v = 0; v < g->V; v++) {
                    if (g->adj[u][v] != INF && dist[u] != INF &&
                        dist[u] + g->adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + g->adj[u][v];
                    }
                }
            }
        }

        // Check for back edges to form cycles
        for (int u = 0; u < g->V; u++) {
            if (g->adj[u][start] != INF && dist[u] != INF) {
                int cycleLength = dist[u] + g->adj[u][start];
                if (cycleLength < shortestCycle) shortestCycle = cycleLength;
            }
        }
    }
    return shortestCycle == INF ? -1 : shortestCycle;
}

// Finds the shortest cycle using Dijkstra's approach
int findShortestCycleDijkstra(Graph* g) {
    int shortestCycle = INF;

    for (int start = 0; start < g->V; start++) {
        int dist[MAX];
        bool visited[MAX] = { false };

        for (int i = 0; i < g->V; i++) dist[i] = INF;  // Initialize distances
        dist[start] = 0;

        // Dijkstra’s algorithm for shortest path
        for (int count = 0; count < g->V - 1; count++) {
            int u = minDistance(dist, visited, g->V);
            visited[u] = true;

            // Update distances to adjacent vertices
            for (int v = 0; v < g->V; v++) {
                if (!visited[v] && g->adj[u][v] != INF && dist[u] != INF &&
                    dist[u] + g->adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + g->adj[u][v];
                }
            }
        }

        // Check for back edges to form cycles
        for (int v = 0; v < g->V; v++) {
            if (g->adj[v][start] != INF && dist[v] != INF) {
                int cycleLength = dist[v] + g->adj[v][start];
                if (cycleLength < shortestCycle) shortestCycle = cycleLength;
            }
        }
    }
    return shortestCycle == INF ? -1 : shortestCycle;
}

int main() {
    Graph g;
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    initGraph(&g, V);  // Initialize the graph structure

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        g.adj[src][dest] = weight;  // Set edge weight in graph
    }

    // Find and print shortest cycles using both approaches
    int resultBellmanFord = findShortestCycleBellmanFord(&g);
    int resultDijkstra = findShortestCycleDijkstra(&g);

    printf("Shortest cycle length using Bellman-Ford: %d\n", resultBellmanFord);
    printf("Shortest cycle length using Dijkstra: %d\n", resultDijkstra);

    return 0;
}
