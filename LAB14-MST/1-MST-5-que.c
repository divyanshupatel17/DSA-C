Problem 1: Kruskal with Budget Constraint

Operations Used:

Edge sorting (qsort)
Find parent with path compression
Union sets with rank
MST weight tracking


Methods Used:

Kruskal's Algorithm with budget check
Union-Find (DSU) for cycle detection
Quick Sort for edge sorting


Alternative Methods:

Prim's Algorithm with budget constraint
Binary Heap implementation
DFS/BFS for checking connectivity



Problem 2: Prim's with Weight Limit

Operations Used:

Edge sorting
Path finding with DFS
MST construction
Query processing


Methods Used:

Modified Prim's Algorithm
DFS for path verification
Adjacency List representation
Union-Find for MST


Alternative Methods:

Dijkstra's Algorithm for paths
Binary Search on edge weights
Floyd-Warshall for all paths



Problem 3: Fiber Optic Installation

Operations Used:

Edge comparison and sorting
Component merging
Cost tracking
MST construction


Methods Used:

Standard Kruskal's Algorithm
Union-Find data structure
Path compression optimization
Rank-based union


Alternative Methods:

Prim's with adjacency matrix
Boruvka's Algorithm
Clustering approach



Problem 4: Railway Track Construction

Operations Used:

Track segment sorting
Component connectivity check
Cost calculation
MST verification


Methods Used:

Basic Kruskal's Algorithm
Union-Find with path compression
Quick Sort for track sorting
Component tracking


Alternative Methods:

Prim's with priority queue
Recursive DFS approach
Greedy selection method



Common Elements Across Problems:

Data Structures Used:

Edge/Track struct
Union-Find arrays
Rank arrays


Core Operations:

Edge sorting: O(E log E)
Find operation: O(α(n))
Union operation: O(α(n))


Optimization Techniques:

Path compression
Union by rank
Efficient sorting

==================================================================================================================================================================================================
==================================================================================================================================================================================================
==================================================================================================================================================================================================
==================================================================================================================================================================================================
1.
Create a Kruskal Algorithm to work within a specified budget constraint. 



Given an undirected graph with weighted edges and a budget limit, find the minimum spanning tree that connects all vertices while staying within the budget. Consider this an optimization problem where the goal is to maximize the total edge weight while keeping it below or equal to the budget.

Input format :
The first line of input consists of three space-separated integers, representing the number of vertices (V), edges (E), and budget.

The next E lines contain the edges represented by (source, destination, weight).

Output format :
The output prints the minimum cost of the spanning tree within the specified budget.

If it is not possible, print "A valid MST within the budget is not possible."



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ V, E ≤ 100

1 ≤ weight ≤ 1000

1 ≤ budget ≤ 10000

Sample test cases :
Input 1 :
3 3 5
1 2 2
2 3 3
3 1 4
Output 1 :
Minimum Cost Spanning Tree within the budget: 5
Input 2 :
5 7 25
1 2 10
1 3 15
2 3 5
2 4 20
3 4 7
4 5 8
1 5 25
Output 2 :
A valid MST within the budget is not possible.
Note :

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100  // Maximum number of edges

// Define a structure for edges with source, destination, and weight
typedef struct {
    int src, dest, weight;
} Edge;

// Function to find the root parent of a node in the union-find structure
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    // Path compression for efficiency
    return parent[i] = find(parent, parent[i]);
}

// Function to union two sets (by rank) in the union-find structure
void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    // Attach smaller rank tree under root of higher rank tree
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        // If ranks are the same, make one as root and increment its rank
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Comparison function for sorting edges by weight in ascending order
int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Kruskal's Algorithm with budget constraint
void kruskal(Edge edges[], int V, int E, int budget) {
    // Sort edges based on weight using quicksort
    qsort(edges, E, sizeof(edges[0]), compare);

    // Arrays for union-find structure
    int parent[V + 1], rank[V + 1];
    for (int i = 0; i <= V; i++) {
        parent[i] = i;  // Initialize each vertex as its own parent (self-loop)
        rank[i] = 0;    // Initialize rank as 0 for all vertices
    }

    int mst_weight = 0;  // To track the weight of the MST
    int mst_edges = 0;   // To count edges in the MST

    // Loop through sorted edges
    for (int i = 0; i < E && mst_weight <= budget; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        // Check if adding this edge creates a cycle
        if (find(parent, u) != find(parent, v)) {
            mst_weight += w;  // Add edge weight to MST total weight
            mst_edges++;       // Increment edge count for MST
            unionSet(parent, rank, u, v);  // Union the sets of u and v
        }
    }

    // Check if we have a valid MST that connects all vertices within budget
    if (mst_edges == V - 1 && mst_weight <= budget)
        printf("Minimum Cost Spanning Tree within the budget: %d\n", mst_weight);
    else
        printf("A valid MST within the budget is not possible.\n");
}

int main() {
    int V, E, budget;
    scanf("%d %d %d", &V, &E, &budget);  // Read vertices, edges, and budget

    Edge edges[MAX_EDGES];  // Array to store all edges

    // Input each edge with source, destination, and weight
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    // Run Kruskal's algorithm with budget constraint
    kruskal(edges, V, E, budget);
    return 0;
}



Above Solution : Kruskal's algorithm with a budget constraint using Disjoint Set Union (DSU) for cycle detection.


Alternative Solutions : Prim's Algorithm with budget constraint


2.

Problem Statement



You are given a graph with N vertices and M edges. Each edge has a weight associated with it. You need to process Q queries, where each query consists of a source vertex, a destination vertex, and a weight limit. For each query, you need to determine if there exists a path between the source and destination vertices in the graph such that the weight of every edge on the path is less than or equal to the weight limit.



Use Prim''s Algorithm to solve this.



Example



Input: 

4

4

0 1 2

1 2 3

2 3 4

3 0 5

2

0 3 7

1 2 2



Output: 

Exists path between 0 and 3 with limit 7: true

Exists path between 1 and 2 with limit 2: false



Explanation:

In this case, the MST contains the edge (0, 1) with weight 2 and the edge (1, 2) with weight 3. The total weight of the path is 5, which is less than the limit of 7. Therefore, the output for the first query is "Exists path between 0 and 3 with limit 7: true". 

The MST contains the edge (0, 1) with weight 2, but the weight limit is also 2. Since the weight of the edge is equal to the limit, we cannot include this edge in the path. Therefore, the output for the second query is "Exists path between 1 and 2 with limit 2: false".

Input format :
The first line of input contains an integer N, representing the number of vertices in the graph.

The second line of input contains an integer M, representing the number of edges in the graph.

The next M lines contain three space-separated integers each: U V W, representing an edge between vertices U and V with weight W.

The next line contains an integer Q, representing the number of queries.

The next Q lines contain three space-separated integers each: S D L, representing a query with source vertex S, destination vertex D, and weight limit L.

Output format :
For each query, the output should indicate whether there exists a path between the source vertex and the destination vertex within the given weight limit.

The output format should be:

"Exists path between X and Y with limit W: true" if a path exists within the weight limit.

"Exists path between X and Y with limit W: false" if a path does not exist within the weight limit.

Code constraints :
2 <= N <= 105

1 <= M <= 2 * 105

1 <= Q <= 105

0 <= U, V, S, D < N

1 <= W, L <= 109

Sample test cases :
Input 1 :
4
4
0 1 2
1 2 3
2 3 4
3 0 5
2
0 3 7
1 2 2
Output 1 :
Exists path between 0 and 3 with limit 7: true
Exists path between 1 and 2 with limit 2: false
Input 2 :
5
6
0 1 3
1 2 2
2 3 4
3 4 1
4 0 2
1 3 3
2
0 4 6
2 4 7
Output 2 :
Exists path between 0 and 4 with limit 6: true
Exists path between 2 and 4 with limit 7: true
Note : 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100005
#define MAX_EDGES 200005

// Edge structure to hold the vertices and weight of each edge
typedef struct {
    int u, v, w;
} Edge;

// Node structure for adjacency list to store nodes and their edge weights in MST
typedef struct {
    int node, weight;
} Node;

// Adjacency list to represent MST
Node *mst[MAX_NODES];
int mst_size[MAX_NODES];

// Union-Find structure
int parent[MAX_NODES], rank[MAX_NODES];

// Find function with path compression for Union-Find
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

// Union function with union by rank for Union-Find
void union_set(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (rootX != rootY) {  // Only union if they are in different sets
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Add an edge to the MST's adjacency list
void add_mst_edge(int u, int v, int weight) {
    mst[u] = (Node *)realloc(mst[u], (mst_size[u] + 1) * sizeof(Node));  // Cast `realloc` to (Node*)
    mst[u][mst_size[u]].node = v;  // Set the node and weight
    mst[u][mst_size[u]].weight = weight;
    mst_size[u]++;  // Increase the edge count for node u
}

// Compare edges based on weight, used in sorting edges for Prim's algorithm
int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

// Depth-First Search (DFS) to find if there's a path within weight limit
bool dfs(int u, int target, int limit, bool visited[]) {
    if (u == target) return true;  // If reached the target, return true
    visited[u] = true;  // Mark the current node as visited

    // Traverse all neighbors of u within MST
    for (int i = 0; i < mst_size[u]; i++) {
        int v = mst[u][i].node;
        int weight = mst[u][i].weight;

        // Only continue if edge weight is within the limit and node hasn't been visited
        if (!visited[v] && weight <= limit) {
            if (dfs(v, target, limit, visited)) return true;  // Recurse, return true if path found
        }
    }
    return false;  // If no valid path found, return false
}

// Prim's algorithm to construct the Minimum Spanning Tree (MST)
void prim(Edge edges[], int n, int m) {
    // Sort edges by weight so we can add them in increasing order of weight
    qsort(edges, m, sizeof(Edge), compare_edges);

    // Initialize Union-Find arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Initialize each node's parent to itself
        rank[i] = 0;    // Rank of each node starts at 0
    }

    // Build the MST by adding edges with the smallest weights first
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {  // Add edge if it connects different sets (no cycle)
            add_mst_edge(u, v, w);  // Add the edge to MST adjacency list
            add_mst_edge(v, u, w);  // Ensure it's undirected
            union_set(u, v);        // Union the sets
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[MAX_EDGES];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);  // Input edges
    }

    // Build the MST using Prim's algorithm
    prim(edges, n, m);

    int q;
    scanf("%d", &q);
    while (q--) {
        int s, d, limit;
        scanf("%d %d %d", &s, &d, &limit);

        // Initialize visited array for each DFS search
        bool visited[MAX_NODES] = {false};

        // Check if path exists within the limit using DFS
        if (dfs(s, d, limit, visited))
            printf("Exists path between %d and %d with limit %d: true\n", s, d, limit);
        else
            printf("Exists path between %d and %d with limit %d: false\n", s, d, limit);
    }

    return 0;
}

Data Structures:

Edge: Stores each edge’s vertices u and v and its weight.
Node: Used for the adjacency list representation of the MST, storing node (neighbor) and weight (edge weight).
mst[]: Adjacency list to represent the MST.

Prim’s Algorithm:

We first sort all edges by weight using qsort().
Union-Find Structure: This structure helps avoid cycles by ensuring each added edge connects two disjoint sets (nodes that aren't already connected).
We add edges in increasing weight, using union_set() to merge sets as we add each edge. If two nodes are already in the same set, adding an edge would create a cycle, so we skip it.

DFS for Query Processing:

For each query, we perform DFS starting from the source node, exploring only edges within the specified weight limit.
If we reach the destination within the limit, we output "true"; otherwise, "false".

Alternative Approaches:

Kruskal’s Algorithm: An alternative MST algorithm suitable for sparse graphs with fewer edges.
Binary Search on Edge Weights: This approach can handle very large edge weights by conducting binary search on the weight range. For each weight, build the MST and check connectivity using Union-Find.'

3.

Problem Statement



Imagine you are working as a software engineer in a company that provides solutions for urban planners to optimize fiber optic cable installations in cities. Given the number of buildings, and roads and the cost of installing fiber optic cables between each building. 



Your task is to develop a program that uses Kruskal's algorithm to find the minimum spanning tree for connecting various buildings within a city with minimal cost.

Input format :
The first line of input consists of an integer N, representing the number of buildings.

The second line of input consists of an integer R, representing the number of roads.

The next R lines consist of three space-separated integers representing the first and second buildings and the respective cost of installation.

Output format :
The first line of output prints "Minimum Spanning Tree:" followed by for each edge in the minimum spanning tree, print the connection between the buildings and the cost of laying fiber optic cables for that edge in a newline.

Each edge should be printed in the format "Building X - Building Y: Z". Where X, Y, and Z are integers representing the building numbers(X and Y) and respective cost for installation(Z).

the last line of output prints "Total Cost for Installation: " followed by an integer representing the total cost for installation.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

0 ≤ N ≤ 10

1 ≤ R ≤ 45

1 ≤ Cost ≤ 15

Sample test cases :
Input 1 :
5
7
0 1 5
0 2 10
0 3 8
1 2 3
2 3 6
3 4 12
2 4 7
Output 1 :
Minimum Spanning Tree:
Building 1 - Building 2: 3
Building 0 - Building 1: 5
Building 2 - Building 3: 6
Building 2 - Building 4: 7
Total Cost for Installation: 21
Input 2 :
4
5
0 1 4
0 2 5
1 2 2
1 3 3
2 3 6
Output 2 :
Minimum Spanning Tree:
Building 1 - Building 2: 2
Building 1 - Building 3: 3
Building 0 - Building 1: 4
Total Cost for Installation: 9
Note :'

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 45
#define MAX_BUILDINGS 10

// Edge structure to store information about each road
typedef struct {
    int u, v, cost; // Buildings connected by the road and cost of installation
} Edge;

Edge edges[MAX_EDGES];     // Array to hold all roads/edges
int parent[MAX_BUILDINGS]; // Array to hold the parent of each building (for Union-Find)
int rank[MAX_BUILDINGS];   // Array to hold the rank of each building (for Union-Find)

// Comparison function to sort edges by cost, for Kruskal's algorithm
int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}

// Find function with path compression to find the root of a building in Union-Find
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union function with union by rank to merge two sets in Union-Find
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) { // Only merge if they are in different sets
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(int n, int r) {
    // Sort edges by cost
    qsort(edges, r, sizeof(Edge), compare_edges);

    // Initialize Union-Find
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each building is its own parent initially
        rank[i] = 0;   // Rank starts at 0
    }

    int mst_cost = 0; // Total cost of MST
    int edges_in_mst = 0; // Count of edges in the MST

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < r && edges_in_mst < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int cost = edges[i].cost;

        // Check if adding this edge would form a cycle
        if (find(u) != find(v)) { // If u and v are in different sets
            union_set(u, v); // Union them
            printf("Building %d - Building %d: %d\n", u, v, cost); // Print the edge in MST
            mst_cost += cost; // Add cost to total MST cost
            edges_in_mst++; // Increment count of edges in MST
        }
    }
    printf("Total Cost for Installation: %d\n", mst_cost); // Print the total cost of MST
}

int main() {
    int n, r;
    scanf("%d", &n); // Number of buildings
    scanf("%d", &r); // Number of roads

    for (int i = 0; i < r; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost); // Input each road/edge
    }

    kruskal(n, r); // Call Kruskal's algorithm to find MST

    return 0;
}



Explanation of Each Part
Data Structures:

Edge struct to store each edge with two buildings (u, v) and the cost.
edges array to store all edges.
parent and rank arrays for Union-Find.
Union-Find Functions:

Find: Uses path compression to make future operations faster by pointing nodes directly to the root of their component.
Union: Uses union by rank to keep the Union-Find tree flat, combining trees based on rank to optimize further.
Kruskal's Algorithm:

Sorting: All edges are sorted by cost to ensure that we add the minimum cost edge each time.
MST Construction: For each edge, we check if it connects two different sets (no cycle). If it does, we add it to the MST and union the sets.
Termination: The loop stops once we have N-1 edges in the MST.
Alternative Methods (for additional context):

Prim’s Algorithm could also be used to find MST, particularly for dense graphs, but it’s more complex to implement than Kruskal’s when edges are explicitly listed.
Union-Find without Rank is possible but would be less efficient.

'
4.

Problem Statement



You are given a set of cities in a country and the cost of building railway track segments to connect them. Your task is to find the minimum cost required to build the railway tracks and connect all the cities. The cost of each track segment is given, along with the source city and destination city to which it connects.



Write a program that takes the number of cities, the number of track segments, and the details of each track segment as input. Implement Kruskal's Algorithm to calculate the minimum cost of building the railway tracks.



Example



Input: 

3

3

0 1 4

1 2 5

0 2 3



Output: 

7



Explanation:

The input specifies 3 cities and 3 track segments with their corresponding weights. 



The track segments are:

Track Segment 1: Connects city 0 and city 1, with a weight of 4.
Track Segment 2: Connects city 1 and city 2 with a weight of 5.
Track Segment 3: Connects city 0 and city 2 with a weight of 3.
The algorithm finds the minimum cost to build railway tracks connecting all cities. In this case, the minimum spanning tree includes track segment 3 (0-2 with weight 3) and track segment 1 (0-1 with weight 4). The total cost is 3 + 4 = 7.

Input format :
The first line of input consists of an integer N, representing the number of cities.

The second line consists of an integer M, representing the number of track segments.

For each M track segment, provide the source city (0-based index), destination city (0-based index), and the weight (cost) of constructing the track segment.

Output format :
If it is possible to connect all cities, print the minimum cost to build the railway tracks.

Otherwise, print "It is not possible to connect all cities."



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N, M ≤ 10

Sample test cases :
Input 1 :
3
3
0 1 4
1 2 5
0 2 3
Output 1 :
7
Input 2 :
6
8
0 1 1
1 2 2
2 3 3
3 4 4
4 0 5
1 4 6
1 3 7
2 4 8
Output 2 :
It is not possible to connect all cities.
Note :

'
#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 45
#define MAX_CITIES 10

// Edge structure to store information about each track segment
typedef struct {
    int u, v, weight; // Cities connected by the track and cost of construction
} Edge;

Edge edges[MAX_EDGES];     // Array to hold all track segments
int parent[MAX_CITIES];    // Array for Union-Find parent references
int rank[MAX_CITIES];      // Array for Union-Find rank optimization

// Comparison function to sort edges by weight (for Kruskal's algorithm)
int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Find function with path compression in Union-Find
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union function with union by rank in Union-Find
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) { // Merge only if different components
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal's algorithm to find the minimum cost to connect all cities
int kruskal(int n, int m) {
    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), compare_edges);

    // Initialize Union-Find data structures
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each city is its own parent initially
        rank[i] = 0;   // Rank starts at 0
    }

    int mst_cost = 0; // Total cost of MST
    int edges_in_mst = 0; // Track number of edges added to MST

    for (int i = 0; i < m && edges_in_mst < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if adding this edge forms a cycle
        if (find(u) != find(v)) { // If u and v are in different sets
            union_set(u, v); // Union the sets
            mst_cost += weight; // Add weight to total cost
            edges_in_mst++; // Increment the count of edges in MST
        }
    }

    // Check if we have connected all cities
    if (edges_in_mst == n - 1) {
        return mst_cost; // Return the total cost for MST
    } else {
        return -1; // Return -1 if it's not possible to connect all cities
    }
}

int main() {
    int n, m;
    scanf("%d", &n); // Number of cities
    scanf("%d", &m); // Number of track segments

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight); // Input each track segment
    }

    int result = kruskal(n, m); // Call Kruskal's algorithm to find MST cost

    if (result != -1) {
        printf("%d\n", result); // Print the minimum cost if all cities are connected
    } else {
        printf("It is not possible to connect all cities.\n"); // Print message if connection is not possible
    }

    return 0;
}


Explanation of Key Parts
Data Structures:

Edge struct holds each track’s source, destination, and construction cost.
Arrays parent and rank are used for Union-Find operations to manage connected components.
Union-Find Functions:

Find: Utilizes path compression to keep components flat, making future operations more efficient.
Union: Uses union by rank to keep the Union-Find structure balanced and avoid deep trees.
Kruskal's Algorithm:

Sorting Edges: First, the edges are sorted by cost to ensure the smallest edge is considered first.
MST Construction: For each edge, it checks if it forms a cycle by ensuring the endpoints are in different sets. If they are, it adds the edge and merges the components.
Termination: Once we have N-1 edges, the MST is complete if all cities are connected. Otherwise, it prints that it's not possible to connect all cities.
Alternative Approaches:

Prim’s Algorithm: Prim’s is also suitable for finding MST but is usually implemented on graphs represented by adjacency lists or matrices, which may not be as efficient as Kruskal’s with an edge list for sparse graphs.