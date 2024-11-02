WRITE IN QUESTION WISE LIKE EXAMPLE Problem        Operation                         Method Used                Alternative Methods

1            BFS traversal                     bfs()                       DFS traversal
2            Check bipartiteness using BFS     isBipartite()                DFS for bipartite checking
3           Longest consecutive path search     findLongestPath() (DFS)    BFS for path finding
4            Connected components             BFS/DFS                     Use DFS instead of BFS

1.

Problem Statement



You are given a set of cities and the cost of connecting each pair of cities. Your task is to find the minimum cost to connect all the cities using Prim's Algorithm and the minimum spanning tree.



Example



Input: 

5

6

0 1 4

0 2 3

1 2 2

1 3 1

2 3 4

3 4 2



Output: 

8



Explanation:

The minimum spanning tree for this input is as follows:

City 0 is connected to City 2 at a cost of 3.

City 2 is connected to City 1 at a cost of 2.

City 1 is connected to City 3 at a cost of 1.

City 3 is connected to City 4 at a cost of 2.



The total cost of these connections is 3 + 2 + 1 +2 = 8, which is printed as the output.

Input format :
The first line of input contains an integer numCities, representing the number of cities (vertices)

The second line contains an integer numConnections, representing the number of connections (edges) between the cities.

The next numConnections lines contain three space-separated integers: source, destination, and cost, representing a connection between a city's source and destination with the given cost.

Output format :
The output prints the minimum cost required to connect all the cities.

Code constraints :
1 ≤ numCities ≤ 105

Sample test cases :
Input 1 :
5
6
0 1 4
0 2 3
1 2 2
1 3 1
2 3 4
3 4 2
Output 1 :
8
Input 2 :
4
5
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
Output 2 :
7
Note :

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 100

// Function to find the city with the minimum key value
int minKey(int key[], int visited[], int numCities) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numCities; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's Algorithm
int prim(int graph[MAX_CITIES][MAX_CITIES], int numCities) {
    int parent[MAX_CITIES]; // Store the resultant MST
    int key[MAX_CITIES];    // Key values used to pick the minimum weight edge
    int visited[MAX_CITIES]; // Track visited cities

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < numCities; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0; // Starting from the first city
    parent[0] = -1; // First node is root

    // Find the MST for all vertices
    for (int count = 0; count < numCities - 1; count++) {
        int u = minKey(key, visited, numCities); // Get the minimum key vertex
        visited[u] = 1; // Mark the picked city as visited

        // Update key value and parent index of the adjacent cities
        for (int v = 0; v < numCities; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate the total cost of the minimum spanning tree
    int totalCost = 0;
    for (int i = 1; i < numCities; i++) {
        totalCost += graph[i][parent[i]];
    }
    return totalCost;
}

int main() {
    int numCities, numConnections;
    scanf("%d %d", &numCities, &numConnections);

    // Initialize the adjacency matrix
    int graph[MAX_CITIES][MAX_CITIES] = {0};
    for (int i = 0; i < numConnections; i++) {
        int src, dest, cost;
        scanf("%d %d %d", &src, &dest, &cost);
        graph[src][dest] = cost; // Undirected graph
        graph[dest][src] = cost; // Since it's undirected
    }

    int minCost = prim(graph, numCities);
    printf("%d\n", minCost); // Output the minimum cost
    return 0;
}

Key Operations of Prim's Algorithm:
Initialization:

Create an adjacency matrix to store the costs of connecting each pair of cities (vertices).
Initialize arrays to keep track of the minimum key values (key), the parent nodes (parent), and whether a city has been visited (visited).
Finding the Minimum Key Vertex:

Use a helper function (minKey) to find the vertex with the smallest key value that hasn't been added to the MST yet.
Updating Costs:

For the selected vertex, update the key values of its adjacent vertices if the new edge offers a cheaper connection to the MST.
Constructing the MST:

Repeat the process until all vertices are included in the MST, at which point calculate the total cost of the MST by summing the weights of the edges included.
Alternative Algorithms for Finding Minimum Spanning Trees:
Kruskal's Algorithm:

Description: This algorithm sorts all the edges in the graph by weight and adds them one by one to the MST, provided they do not form a cycle (using a union-find data structure to track connected components).
Complexity: 
𝑂
(
𝐸
log
⁡
𝐸
)
O(ElogE) or 
𝑂
(
𝐸
log
⁡
𝑉
)
O(ElogV) where 
𝐸
E is the number of edges and 
𝑉
V is the number of vertices. It is more efficient for sparse graphs.

2.

'
Problem statement



Implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a given connected, undirected, and weighted graph.

Input format :
The input consists of the following:

The number of vertices (V) in the graph.

The number of edges (E) in the graph.

E lines represent the edges, each containing three space-separated integers: the source vertex (u), the destination vertex (v), and the weight of the edge (w).

Output format :
The output consists of the following:

The edges in the constructed MST are each in the format: "u -- v == weight".

The total weight of the Minimum Spanning Tree, in the format: "Minimum Spanning Tree: weight".

Sample test cases :
Input 1 :
4
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Output 1 :
Edges in the constructed MST:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Spanning Tree: 25
Input 2 :
5
6
0 1 2
1 2 1
2 3 3
3 4 4
4 0 5
0 2 6
Output 2 :
Edges in the constructed MST:
1 -- 2 == 1
0 -- 1 == 2
2 -- 3 == 3
3 -- 4 == 4
Minimum Spanning Tree: 15
Note :'

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

// Union-Find structure to keep track of connected components
typedef struct {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} UnionFind;

// Function to initialize the Union-Find structure
void initUnionFind(UnionFind *uf, int V) {
    for (int i = 0; i < V; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

// Find function with path compression
int find(UnionFind *uf, int u) {
    if (uf->parent[u] != u) {
        uf->parent[u] = find(uf, uf->parent[u]); // Path compression
    }
    return uf->parent[u];
}

// Union function by rank
void unionSets(UnionFind *uf, int u, int v) {
    int rootU = find(uf, u);
    int rootV = find(uf, v);
    
    if (rootU != rootV) {
        if (uf->rank[rootU] > uf->rank[rootV]) {
            uf->parent[rootV] = rootU;
        } else if (uf->rank[rootU] < uf->rank[rootV]) {
            uf->parent[rootU] = rootV;
        } else {
            uf->parent[rootV] = rootU;
            uf->rank[rootU]++;
        }
    }
}

// Comparator function for sorting edges by weight
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's Algorithm
void kruskal(int V, int E, Edge edges[]) {
    UnionFind uf;
    initUnionFind(&uf, V);
    
    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compareEdges);
    
    int totalWeight = 0;
    printf("Edges in the constructed MST:\n");
    
    for (int i = 0; i < E; i++) {
        Edge edge = edges[i];
        // If including this edge doesn't cause a cycle
        if (find(&uf, edge.u) != find(&uf, edge.v)) {
            unionSets(&uf, edge.u, edge.v);
            printf("%d -- %d == %d\n", edge.u, edge.v, edge.weight);
            totalWeight += edge.weight;
        }
    }
    
    printf("Minimum Spanning Tree: %d\n", totalWeight);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    Edge edges[MAX_EDGES];
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    kruskal(V, E, edges); // Run Kruskal's Algorithm
    return 0;
}

Explanation of the Code:
Data Structures:

An Edge structure is used to store the edges of the graph, consisting of two vertices (u, v) and their weight.
A UnionFind structure is used to manage connected components for cycle detection.
Union-Find Functions:

initUnionFind: Initializes the parent and rank arrays for Union-Find.
find: Implements path compression to find the root of a set.
unionSets: Merges two sets based on rank to maintain a balanced tree.
Sorting:

Edges are sorted by weight using the qsort function with a custom comparator (compareEdges).
Kruskal's Algorithm:

Iterates through the sorted edges, adding them to the MST if they do not form a cycle (checked using Union-Find).
Input Handling:

Reads the number of vertices and edges and then reads each edge into an array.
Output:

Prints each edge included in the MST and the total weight of the MST.
Key Points:
Time Complexity: The overall time complexity of Kruskal's Algorithm is 
𝑂
(
𝐸
log
⁡
𝐸
)
O(ElogE) due to sorting the edges. The union-find operations are nearly constant time due to path compression and union by rank.

Alternative Algorithms:

Prim''s Algorithm: Works by expanding the MST one vertex at a time and is often used for dense graphs.

// BELOW BOTH CODE ARE WRONG  

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
typedef struct {
    int src;    // Source vertex
    int dest;   // Destination vertex
    int weight; // Weight/cost of edge
} Edge;

// Structure to represent the graph
typedef struct {
    int V, E;   // Number of vertices and edges
    Edge* edges;// Array of edges
} Graph;

// Method: Memory allocation for graph creation
// Alternative: Could use adjacency list or matrix representation
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Method: Subset structure for Union-Find
// Alternative: Could use simple array for small datasets
typedef struct {
    int parent;
    int rank;
} Subset;

// Method: Find operation with path compression
// Alternative: Simple find without path compression (less efficient)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Method: Union by rank
// Alternative: Simple union without rank (could lead to skewed trees)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Method: Comparison function for qsort
// Alternative: Could implement other sorting algorithms like merge sort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Method: Kruskal's MST Algorithm
// Alternative Methods:
// 1. Prim's Algorithm (better for dense graphs)
// 2. Boruvka's Algorithm
// 3. Reverse-Delete Algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];  // Array to store MST
    int e = 0;  // Index for result[]
    int i = 0;  // Index for sorted edges
    int totalWeight = 0;  // Initialize total weight
    
    // Method: Quick Sort for edge sorting
    // Alternative: Heap Sort or Merge Sort
    qsort(graph->edges, graph->E, sizeof(Edge), compareEdges);
    
    // Method: Union-Find data structure initialization
    // Alternative: Could use simple array for very small graphs
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Method: Iterative edge selection
    // Alternative: Could use recursive approach
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result[e] = next_edge;
            totalWeight += next_edge.weight;  // Add weight to total
            Union(subsets, x, y);
            e++;
        }
    }

    // Output formatting
    printf("Edges in the constructed MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    printf("Minimum Spanning Tree: %d\n", totalWeight);
    
    free(subsets);
}

int main() {
    int V, E;
    scanf("%d", &V); // Input number of vertices
    scanf("%d", &E); // Input number of edges
    
    // Method: Dynamic memory allocation
    // Alternative: Static array for small, fixed sizes
    Graph* graph = createGraph(V, E);
    
    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
    
    KruskalMST(graph);
    
    free(graph->edges);
    free(graph);
    return 0;
}


, 
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function to compare two edges (used for sorting)
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Find function with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function by rank
void unionByRank(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(int V, int E, Edge edges[]) {
    Edge result[V]; // To store the resultant MST
    int e = 0; // Count of edges in MST
    int i = 0; // Initial index of sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Create V subsets with single elements
    Subset *subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge and check for cycles
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        // If including this edge does not cause a cycle
        if (x != y) {
            result[e++] = next_edge; // Include it in the result
            unionByRank(subsets, x, y); // Union of the two subsets
        }
    }

    // Print the resulting MST
    printf("Edges in the constructed MST:\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Minimum Spanning Tree: %d\n", totalWeight);

    free(subsets);
}

int main() {
    int V, E;

    // Input number of vertices and edges
    scanf("%d", &V);
    scanf("%d", &E);

    Edge *edges = (Edge*)malloc(E * sizeof(Edge));

    // Input all edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Call Kruskal's algorithm
    kruskal(V, E, edges);

    free(edges);
    return 0;
}


