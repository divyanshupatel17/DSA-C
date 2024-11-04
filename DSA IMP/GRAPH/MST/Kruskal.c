#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices in the graph
#define INF 999999 // Representation of no edge between vertices

// Structure to represent an edge with a source, destination, and weight
struct Edge {
    int src, dest, weight;
};

// Structure to represent subsets for union-find
// Each subset has a parent (for find operation) and rank (for union by rank)
struct Subset {
    int parent, rank;
};

// Function to find the root of a subset (with path compression to optimize performance)
int find(struct Subset subsets[], int i) {
    // If i is not the root, find its parent recursively
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Function to union two subsets by rank
// Attach the tree with the smaller rank to the tree with the larger rank
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x); // Find root of subset x
    int yroot = find(subsets, y); // Find root of subset y
    
    // Attach smaller rank tree under root of the higher rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        // If ranks are equal, make one root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function for qsort to sort edges by their weights in ascending order
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm for finding the MST
void kruskal(int graph[MAX][MAX], int V) {
    struct Edge edges[MAX * MAX]; // Array to hold all edges of the graph
    int edgeCount = 0; // Counter to keep track of the number of edges
    
    // Convert adjacency matrix into an edge list
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) { // Check if edge exists
                edges[edgeCount++] = (struct Edge){i, j, graph[i][j]}; // Store edge in list
            }
        }
    }

    // Sort edges by their weights in ascending order
    qsort(edges, edgeCount, sizeof(edges[0]), compareEdges);

    // Create subsets for each vertex (for union-find)
    struct Subset subsets[MAX];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i; // Initially, each vertex is its own parent
        subsets[i].rank = 0; // Initial rank is 0
    }

    // Array to store edges included in the MST
    struct Edge result[MAX];
    int e = 0; // Counter for number of edges in the MST

    // Process each edge in sorted order
    for (int i = 0; i < edgeCount && e < V - 1; i++) {
        struct Edge nextEdge = edges[i]; // Get the next edge with minimum weight

        // Find the root of the subsets of both vertices of the edge
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, add it to the MST
        if (x != y) {
            result[e++] = nextEdge; // Include edge in MST
            Union(subsets, x, y); // Union the subsets
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix
    // Use INF (999999) to represent no edge between vertices
    printf("Enter the adjacency matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Execute Kruskal's algorithm to find the MST
    kruskal(graph, V);

    return 0;
}

/*
input 

Enter the number of vertices and edges: 4 5
Enter each edge (source, destination, weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4


output

Edge     Weight
2 - 3    4
0 - 3    5
0 - 1    10

*/