Summary of BFS and DFS Operations

Problem	    Operation	                     Method Used	            Alternative Methods

1	        BFS traversal	                 bfs()               	    DFS traversal
2	        Check bipartiteness using BFS	 isBipartite()	            DFS for bipartite checking
3       	Longest consecutive path search	 findLongestPath() (DFS)	BFS for path finding
4	        Connected components	         BFS/DFS             	    Use DFS instead of BFS


1,.
Problem Statement



You are designing a navigation system for a city with multiple interconnected cities. The cities are represented as vertices, and the connections between cities are represented as edges in a graph. 



Your task is to implement a program that performs a breadth-first search (BFS) traversal on the graph, starting from a given source city, and outputs the order in which the cities are visited.

Input format :
The first line of input consists of two space-separated integers, v, and e, representing the total number of cities and the number of connections between cities.

The next e lines consist of the two space-separated integers a and b, representing a connection from city a to city b.

The last line consists of a single integer s, representing the source city from which BFS traversal should start.

Output format :
The output prints the order in which the cities are visited during the BFS traversal, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ v ≤ 100

0 ≤ e ≤ v * (v - 1)

0 ≤ s < v

Sample test cases :
Input 1 :
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0
Output 1 :
0 1 2 3 4 5 
Input 2 :
3 3
0 1
1 2
2 0
2 
Output 2 :
2 0 1 
Note :

#include <stdio.h>

#define MAX 100

void bfs(int graph[MAX][MAX] , int visited[] , int start , int v){
    int queue[MAX], front=0, rear=0;

    queue[rear++] = start;
    visited[start] = 1;
    
    while(front < rear){
        int city = queue[front++];
        printf("%d ",city);
        
        // add all breadth of graph[city][i]
        for(int i=0 ; i<v ; i++){
            if(graph[city][i] == 1 && !visited[i]){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int v,e; // vertices & edges
    scanf("%d %d",&v,&e);
    
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int visited[MAX] = {0};    // Visited array
    
    for(int i=0 ; i<e ; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b] =1;
        graph[b][a] =1;  // undirected graph
    }
    
    int start;
    scanf("%d",&start);
    
    // perfrom bfs from starting (connected components)
    bfs(graph,visited,start,v);
    printf("\n");
    
    // handling (disconnected components)
    for(int i=0 ; i<v ; i++){
        if(!visited[i]){
            bfs(graph,visited,i,v);
            printf("\n");
        }
    }
    
    
    
}


2.

Problem Statement



You are given a network of n computers, represented by vertices numbered from 0 to n-1. The computers are connected to each other through network cables, forming a communication network. Your task is to determine whether the given network is bipartite or not using the Breadth-first search algorithm.



A network is considered bipartite if it can be divided into two independent sets of computers such that no two computers within the same set are directly connected. In other words, the computers in each set can communicate with computers in the other set but not within their own set.

Input format :
The first line contains an integer n, representing the total number of computers in the network.

The next n lines contain n integers each, representing the adjacency matrix G.

Each integer G[i][j] is either 0 or 1, separated by a space.

The last line contains an integer src, representing the source computer.

Output format :
If the graph is bipartite, print "Yes, the given graph is Bipartite".

If the graph is not bipartite, print "No, the given graph is not Bipartite".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 6

The adjacency matrix will be a square matrix of size n x n.

Each cell in the matrix will contain either 0 or 1.

Sample test cases :
Input 1 :
3
0 1 1
1 0 0
1 0 0
0
Output 1 :
Yes, the given graph is Bipartite
Input 2 :
5
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
3
Output 2 :
No, the given graph is not Bipartite
Note :


#include <stdio.h>

#define MAX 6

// Function to check if the graph is bipartite using BFS
int isBipartite(int graph[MAX][MAX], int n, int src) {
    int color[MAX];
    for (int i = 0; i < n; i++) {
        color[i] = -1;  // -1 means no color assigned
    }

    color[src] = 1;  // Start coloring the source with 1
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];

        // Check for self-loop
        if (graph[u][u] == 1) return 0;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {  // If there is an edge
                if (color[v] == -1) {  // If vertex v is not colored
                    color[v] = 1 - color[u];  // Assign opposite color
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {  // If adjacent vertices have the same color
                    return 0;  // Not bipartite
                }
            }
        }
    }
    return 1;  // Graph is bipartite
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    scanf("%d", &src);

    if (isBipartite(graph, n, src)) {
        printf("Yes, the given graph is Bipartite\n");
    } else {
        printf("No, the given graph is not Bipartite\n");
    }

    return 0;
}


3.

Problem Statement



Given an M × N matrix of characters, find the length of the longest path in the matrix starting from a given character. 



In alphabetical order, all characters in the longest path should be increasing and consecutive. We are allowed to search the string in all eight possible directions, i.e., North, West, South, East, North-East, North-West, South-East, and South-West. 



Use depth-first search (DFS) to solve this problem.



For example, consider the following matrix of characters:



The length of the longest path with consecutive characters starting from character C is 6. 



The longest path is:



Input format :
The first line of input is an integer n representing the row size.

The second line of input is an integer m representing the column size.

The following lines of input are the characters of the matrix.

The last line of the input is the character for which the length of the longest path is to be found.

Output format :
The output prints the length of the longest path with consecutive characters starting from the given character.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n,m ≤ 5

Sample test cases :
Input 1 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
c
Output 1 :
The length of the longest path with consecutive characters starting from character c is 6
Input 2 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
b
Output 2 :
The length of the longest path with consecutive characters starting from character b is 7
Note :

#include <stdio.h>

#define MAX 5

// Directions arrays for the 8 possible moves
int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// (-1, -1): Up-Left diagonal
// (-1,  0): Up
// (-1,  1): Up-Right diagonal
// ( 0, -1): Left
// ( 0,  1): Right
// ( 1, -1): Down-Left diagonal
// ( 1,  0): Down
// ( 1,  1): Down-Right diagonal

// Utility function to check if the given coordinates are within matrix bounds
int isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Depth-First Search function to find the longest consecutive path from a given character
int findLongestPath(char mat[MAX][MAX], int x, int y, char start, int n, int m) {
    int maxLen = 1;  // At least the start character itself

    // Explore all 8 possible directions
    for (int i = 0; i < 8; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];

        // Check if we can move to this new cell and it's the next consecutive character
        if (isValid(newX, newY, n, m) && mat[newX][newY] == start + 1) {
            int pathLen = 1 + findLongestPath(mat, newX, newY, start + 1, n, m);
            if (pathLen > maxLen) {
                maxLen = pathLen;
            }
        }
    }

    return maxLen;
}

// Function to find the longest path starting from a given character
int longestPath(char mat[MAX][MAX], int n, int m, char start) {
    int longest = 0;

    // Traverse the matrix to find occurrences of the starting character
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == start) {
                // DFS from this cell
                int pathLen = findLongestPath(mat, i, j, start, n, m);
                if (pathLen > longest) {
                    longest = pathLen;
                }
            }
        }
    }

    return longest;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char mat[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }

    char startChar;
    scanf(" %c", &startChar);

    int result = longestPath(mat, n, m, startChar);
    printf("The length of the longest path with consecutive characters starting from character %c is %d\n", startChar, result);

    return 0;
}


4.

Problem Statement



Given an undirected graph represented by an adjacency matrix, the task is to find and print all the connected components in the graph.



Example



Input 

5

1 0

2 1

3 4

-1 -1

Output 

Following are connected components:

0 1 2 

3 4 



Explanation

In the given graph, there are two connected components:

Component 1: Vertices 0, 1, and 2 are connected to each other.

Component 2: Vertices 3 and 4 are connected to each other.

Input format :
The first line of input consists of an integer V, representing the number of vertices in the graph.

The next line of input consists of pairs of integers u and v separated by a space, representing an edge between vertex u and vertex v in the graph.

The input terminates when -1 -1 is encountered.

Output format :
The output prints "Following are connected components:" followed by the connected components.

Each connected component should be printed on a separate line.

Each line should contain the vertices that belong to the same connected component, separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ V ≤ 10

0 ≤ u, v < V

Vertices are numbered from 0 to vertices-1

Sample test cases :
Input 1 :
5
1 0
2 1
3 4
-1 -1
Output 1 :
Following are connected components:
0 1 2 
3 4 
Input 2 :
7
0 1
1 2
2 0
3 4
4 5
5 6
-1 -1
Output 2 :
Following are connected components:
0 1 2 
3 4 5 6 
Note :

#include <stdio.h>

#define MAX_V 10  // Maximum number of vertices

// Function to perform DFS and find connected components
void dfs(int graph[MAX_V][MAX_V], int visited[], int v, int node) {
    visited[node] = 1;  // Mark the current node as visited
    printf("%d ", node); // Print the current node

    // Explore all vertices connected to the current node
    for (int i = 0; i < v; i++) {
        if (graph[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
            dfs(graph, visited, v, i); // Recursive DFS call
        }
    }
}

// Function to find and print all connected components
void findConnectedComponents(int graph[MAX_V][MAX_V], int v) {
    int visited[MAX_V] = {0}; // Array to keep track of visited vertices

    printf("Following are connected components:\n");
    for (int i = 0; i < v; i++) {
        if (!visited[i]) { // If the vertex is not visited
            dfs(graph, visited, v, i); // Start DFS from this vertex
            printf("\n"); // New line after each component
        }
    }
}

int main() {
    int v; // Number of vertices
    scanf("%d", &v);

    int graph[MAX_V][MAX_V] = {0}; // Adjacency matrix initialized to 0

    // Input edges until -1 -1 is encountered
    while (1) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u == -1 && w == -1) {
            break; // Terminate input on -1 -1
        }
        graph[u][w] = 1; // Add edge to the graph
        graph[w][u] = 1; // Since it's undirected, add both directions
    }

    findConnectedComponents(graph, v); // Find and print connected components

    return 0;
}


5,

Problem Statement



Given a directed graph represented using an adjacency list, the task is to find the length of the shortest cycle in the graph. A cycle is a path that starts and ends at the same vertex, and the length of the cycle is defined as the sum of the weights of all the edges in the cycle. If no cycle is found in the graph, output a message indicating that no cycle exists.



Example

Input 

4

4

0 1 2

1 2 3

2 0 4

3 1 5

Output 

Length of the shortest cycle: 9



Explanation

After exploring all starting vertices, the code checks for cycles by examining the distances. If an edge leads back to the starting vertex, it means there is a cycle. In this case, edge 1 (vertex 1) leads back to the starting vertex 0. The code calculates the length of the cycle by adding the distances of the vertices along the cycle: 2 (0 -> 1) + 3 (1 -> 2) + 4 (2 -> 0) = 9.



Therefore, the output is "Length of the shortest cycle: 9".



Input 2

3

2

0 1 2

1 2 3

Output 2

No cycle was found in the graph.



Explanation

After exploring all starting vertices, the code checks for cycles by examining the distances. If an edge leads back to the starting vertex, it means there is a cycle. However, in this case, there are no edges that lead back to the starting vertex. Hence, there is no cycle in the graph.

Therefore, the output is "No cycle found in the graph."

Input format :
The first line of input consists of an integer v, representing the number of vertices in the graph.

The second line of input consists of an integer e, representing number of edges in the graph.

The next edges lines each contain three integers: source, destination, and weight, representing a directed edge from source to destination with the given weight.

Output format :
If a cycle exists, print "Length of the shortest cycle: X", where X is the length of the shortest cycle.

If no cycle exists, print "No cycle found in the graph".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ v ≤ 5

1 ≤ edges ≤ 7

0 ≤ S, D < V

1 ≤ W ≤ 5

Weights are positive integers.

Sample test cases :
Input 1 :
4
4
0 1 2
1 2 3
2 0 4
3 1 5
Output 1 :
Length of the shortest cycle: 9
Input 2 :
3
2
0 1 2
1 2 3
Output 2 :
No cycle found in the graph.
Input 3 :
3
3
0 1 2
1 2 3
2 0 4
Output 3 :
Length of the shortest cycle: 9
Note :

#include <stdio.h>
#include <limits.h>

#define MAX 5
#define INF INT_MAX

// Function to find shortest cycle in the graph
int findShortestCycle(int graph[MAX][MAX], int V) {
    int shortestCycle = INF;
    
    // Try each vertex as starting point
    for(int start = 0; start < V; start++) {
        // Distance array for shortest paths
        int dist[MAX];
        for(int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;
        
        // Calculate shortest paths
        for(int i = 0; i < V-1; i++) {
            for(int u = 0; u < V; u++) {
                for(int v = 0; v < V; v++) {
                    if(graph[u][v] != INF) {
                        if(dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph[u][v];
                        }
                    }
                }
            }
        }
        
        // Check for cycles back to start vertex
        for(int u = 0; u < V; u++) {
            if(graph[u][start] != INF && dist[u] != INF) {
                int cycleLength = dist[u] + graph[u][start];
                if(cycleLength < shortestCycle) {
                    shortestCycle = cycleLength;
                }
            }
        }
    }
    
    return shortestCycle;
}

int main() {
    int V, E;
    scanf("%d", &V);  // Number of vertices
    scanf("%d", &E);  // Number of edges
    
    // Initialize graph with INF
    int graph[MAX][MAX];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }
    
    // Input edges
    for(int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }
    
    // Find and print shortest cycle
    int result = findShortestCycle(graph, V);
    
    if(result == INF) {
        printf("No cycle found in the graph.\n");
    } else {
        printf("Length of the shortest cycle: %d\n", result);
    }
    
    return 0;
}