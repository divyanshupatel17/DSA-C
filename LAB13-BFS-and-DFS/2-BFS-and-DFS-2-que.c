Problem 	                                    Operation	                                Method Used	        Alternative Methods

1. Cycle Detection in an Undirected Graph	    DFS traversal to check for cycles	        hasCycle() (DFS)	BFS for cycle detection
2. Shortest Path in an Undirected Graph	        BFS traversal to find shortest path	        findPath() (BFS)	Dijkstra's algorithm (for weighted graphs) or DFS with backtracking
'


1.
Problem Statement



Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. The graph is in the form of an adjacency list where adj[i] contains all the nodes ith node is having edge with.

Input format :
The first line of the input consists of an integer V, representing the number of vertices.

The second line of the input consists of an integer E, representing the number of edges.

The next E lines of input consist of a pair of integers representing the start and end nodes for each m edge.

Output format :
The output prints "1" if the graph contains a cycle.

Otherwise, the output prints "0" if the graph does not contain a cycle.



Refer to the sample output for the formatting specifications.

Sample test cases :
Input 1 :
5
5
1 0
0 2
2 1
0 3
3 4
Output 1 :
1
Input 2 :
3
2
0 1
1 2
Output 2 :
0
Note :

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to check for cycle using DFS
bool hasCycle(int graph[MAX][MAX], bool visited[], int V, int curr, int parent) {
   // Mark current vertex as visited
   visited[curr] = true;
   
   // Check all adjacent vertices
   for(int i = 0; i < V; i++) {
       if(graph[curr][i]) { // If there is an edge
           
           // If adjacent vertex is not visited, recursively visit it
           if(!visited[i]) {
               if(hasCycle(graph, visited, V, i, curr))
                   return true;
           }
           
           // If adjacent vertex is visited and not parent, cycle exists 
           else if(i != parent)
               return true;
       }
   }
   return false;
}

int main() {
   int V, E;
   
   // Input number of vertices and edges
   scanf("%d", &V);
   scanf("%d", &E);
   
   // Initialize adjacency matrix
   int graph[MAX][MAX] = {0};
   
   // Input edges
   for(int i = 0; i < E; i++) {
       int src, dest;
       scanf("%d %d", &src, &dest);
       // Add edge to adjacency matrix (undirected)
       graph[src][dest] = 1;
       graph[dest][src] = 1;
   }
   
   // Initialize visited array
   bool visited[MAX] = {false};
   bool cycleFound = false;
   
   // Check for cycle starting from each unvisited vertex
   for(int i = 0; i < V; i++) {
       if(!visited[i]) {
           if(hasCycle(graph, visited, V, i, -1)) {
               cycleFound = true;
               break;
           }
       }
   }
   
   // Print result
   printf("%d\n", cycleFound ? 1 : 0);
   
   return 0;
}


2.

Problem Statement



Given an adjacency matrix representation of a graph, compute the shortest path from a source vertex to a goal vertex using breadth-first search.



In the case of a tie, a smaller indexed vertex should be preferred to a larger one.



Example



Input:

5

0 1 1 0 0 

1 0 1 0 0 

1 1 0 1 0

0 0 1 0 1

0 0 0 1 0

0 4

Output:

3

0 2 3 4

Explanation:

The program outputs the length of the path, which is 3. It then prints the vertices in the path in order, starting from the starting vertex and ending at the ending vertex. The shortest path from the starting vertex to the ending vertex is of length 3 and includes vertices 0 (starting vertex), 2, 3, and 4 (ending vertex).

Input format :
The first line of input is N, the number of vertices in the graph.

Then N lines of inputs have N integers each, separated by a space, denoting the adjacency matrix.

The last line of input is the index of the source and goal separated by space; the indexing starts from 0.

Output format :
The first line of output is the length of the shortest path from the source to the goal vertex.

The second line is the path from the source to the goal (including both the source and goal).

Print "Not found" for an invalid index of the source and the goal is given.



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ N ≤ 7

0 ≤ source, goal < N

Sample test cases :
Input 1 :
5
0 1 1 0 0 
1 0 1 0 0 
1 1 0 1 0
0 0 1 0 1
0 0 0 1 0
0 4
Output 1 :
3
0 2 3 4
Input 2 :
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
0 4
Output 2 :
Not found
Note :

#include <stdio.h>
#define MAX_V 7

// Simple queue structure and operations
typedef struct {
    int data[MAX_V];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Add element to queue
void enqueue(Queue* q, int x) {
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = x;
}

// Remove element from queue
int dequeue(Queue* q) {
    int x = q->data[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return x;
}

// Find shortest path using BFS
void findPath(int g[][MAX_V], int n, int start, int end) {
    // Initialize visited array and parent tracking
    int visited[MAX_V] = {0}, parent[MAX_V];
    Queue q;
    initQueue(&q);
    
    // Start BFS from source
    enqueue(&q, start);
    visited[start] = 1;
    parent[start] = -1;
    
    // BFS traversal
    while (q.front != -1) {
        int curr = dequeue(&q);
        if (curr == end) {
            // Reconstruct and print path
            int path[MAX_V], len = 0;
            for (int v = end; v != -1; v = parent[v])
                path[len++] = v;
            printf("%d\n", len - 1);
            while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
            return;
        }
        // Check all neighbors
        for (int i = 0; i < n; i++)
            if (g[curr][i] && !visited[i]) {
                visited[i] = 1;
                parent[i] = curr;
                enqueue(&q, i);
            }
    }
    printf("Not found\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Validate input size
    if (n < 2 || n > MAX_V) {
        printf("Not found\n");
        return 0;
    }
    
    // Read adjacency matrix
    int graph[MAX_V][MAX_V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    
    // Read and validate source and goal vertices
    int src, goal;
    scanf("%d %d", &src, &goal);
    if (src < 0 || src >= n || goal < 0 || goal >= n) {
        printf("Not found\n");
        return 0;
    }
    
    findPath(graph, n, src, goal);
    return 0;
}