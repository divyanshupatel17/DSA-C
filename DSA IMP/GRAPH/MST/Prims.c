#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices
#define INF 999999  // Representation of no edge between vertices

// Function to find the vertex with the minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V) {
    int min = INF, minIndex;

    // Iterate over all vertices to find the minimum key value
    for (int v = 0; v < V; v++) {
        // Update min if key[v] is smaller and v is not in the MST yet
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;  // Return index of vertex with minimum key value
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        // Print each edge and its weight
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];  // Array to store the MST (parent array)
    int key[MAX];     // Key values used to pick the minimum weight edge
    bool mstSet[MAX]; // Boolean array to represent set of vertices included in MST

    // Initialize key values as INF and mstSet as false for all vertices
    for (int i = 0; i < V; i++) {
        key[i] = INF;  // Set initial key value to infinity
        mstSet[i] = false;  // Mark all vertices as not included in MST
    }

    key[0] = 0;      // Make key of the first vertex as 0 so that it is picked first
    parent[0] = -1;  // First vertex is always the root of the MST

    // The MST will have exactly V-1 edges, so we iterate V-1 times
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick vertex u with the smallest key value not in MST
        mstSet[u] = true; // Include vertex u in MST

        // Update the key and parent for the adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update key[v] only if graph[u][v] is non-zero (edge exists),
            // v is not yet included in MST, and the new key is smaller
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;  // Set u as parent of v in MST
                key[v] = graph[u][v];  // Update key with weight of the edge u-v
            }
        }
    }

    // Print the MST using the parent array
    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[MAX][MAX];

    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix, using INF (999999) to indicate no edge
    printf("Enter the adjacency matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Prim's algorithm to find the MST
    primMST(graph, V);

    return 0;
}

/**
input

Enter the number of vertices: 4
Enter the adjacency matrix (enter 999999 for no edge):
0 4 0 999999
4 0 8 11
0 8 0 7
999999 11 7 0

output

Edge     Weight
0 - 1    4 
0 - 2    0 
2 - 3    7 



 */