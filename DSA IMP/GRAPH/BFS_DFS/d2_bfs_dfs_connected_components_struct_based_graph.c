#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10 // Maximum number of vertices

// Graph structure with adjacency matrix and vertex count
typedef struct {
    int adj[MAX_V][MAX_V]; // Adjacency matrix
    int V;                 // Number of vertices
} Graph;

// Initialize the graph with given vertices, setting all edges to 0
void initGraph(Graph* g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Function to perform DFS and find connected components
void dfs(Graph* g, int visited[], int node) {
    visited[node] = 1;             // Mark the current node as visited
    printf("%d ", node);           // Print the current node

    // Explore all vertices connected to the current node
    for (int i = 0; i < g->V; i++) {
        if (g->adj[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
            dfs(g, visited, i);                   // Recursive DFS call
        }
    }
}

// Function to perform BFS and find connected components
void bfs(Graph* g, int visited[], int startNode) {
    int queue[MAX_V], front = 0, rear = 0;
    visited[startNode] = 1;        // Mark the start node as visited
    queue[rear++] = startNode;     // Enqueue the start node

    while (front < rear) {         // Continue until queue is empty
        int node = queue[front++]; // Dequeue a node
        printf("%d ", node);       // Print the node

        // Explore all vertices connected to the current node
        for (int i = 0; i < g->V; i++) {
            if (g->adj[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = 1;                        // Mark as visited
                queue[rear++] = i;                     // Enqueue the connected node
            }
        }
    }
}

// Function to find and print all connected components using DFS and BFS
void findConnectedComponents(Graph* g) {
    int visited[MAX_V] = {0}; // Array to keep track of visited vertices

    printf("Connected components using DFS:\n");
    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {          // If the vertex is not visited
            dfs(g, visited, i);     // Start DFS from this vertex
            printf("\n");           // New line after each component
        }
    }

    // Reset visited array for BFS
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    printf("Connected components using BFS:\n");
    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {          // If the vertex is not visited
            bfs(g, visited, i);     // Start BFS from this vertex
            printf("\n");           // New line after each component
        }
    }
}

int main() {
    Graph g;
    int v;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    initGraph(&g, v); // Initialize the graph with vertex count

    // Input edges until -1 -1 is encountered
    printf("Enter edges (u v), -1 -1 to end:\n");
    while (1) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u == -1 && w == -1) {
            break; // Terminate input on -1 -1
        }
        g.adj[u][w] = 1; // Add edge to the graph
        g.adj[w][u] = 1; // Since it's undirected, add both directions
    }

    findConnectedComponents(&g); // Find and print connected components

    return 0;
}
