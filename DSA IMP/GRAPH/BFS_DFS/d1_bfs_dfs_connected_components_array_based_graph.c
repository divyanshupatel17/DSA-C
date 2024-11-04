#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10 // Maximum number of vertices

// Function to perform DFS and find connected components
void dfs(int graph[MAX_V][MAX_V], int visited[], int v, int start) {
    visited[start] = 1;           // Mark the current node as visited
    printf("%d ", start);         // Print the current node

    // Explore all vertices connected to the current node
    for (int i = 0; i < v; i++) {
        if (graph[start][i] == 1 && !visited[i]) { // Check for an edge and if not visited
            dfs(graph, visited, v, i);           // Recursive DFS call
        }
    }
}

// Function to perform BFS and find connected components
void bfs(int graph[MAX_V][MAX_V], int visited[], int v, int startNode) {
    int queue[MAX_V], front = 0, rear = 0;
    visited[startNode] = 1;      // Mark the start node as visited
    queue[rear++] = startNode;   // Enqueue the start node

    while (front < rear) {       // Continue until queue is empty
        int node = queue[front++]; // Dequeue a node
        printf("%d ", node);     // Print the node

        // Explore all vertices connected to the current node
        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1 && !visited[i]) { // Check for an edge and if not visited
                visited[i] = 1;                      // Mark as visited
                queue[rear++] = i;                   // Enqueue the connected node
            }
        }
    }
}

// Function to find and print all connected components using DFS and BFS
void findConnectedComponents(int graph[MAX_V][MAX_V], int v) {
    int visited[MAX_V] = {0}; // Array to keep track of visited vertices

    printf("Connected components using DFS:\n");
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {      // If the vertex is not visited
            dfs(graph, visited, v, i); // Start DFS from this vertex
            printf("\n");       // New line after each component
        }
    }

    // Reset visited array for BFS
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    printf("Connected components using BFS:\n");
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {      // If the vertex is not visited
            bfs(graph, visited, v, i); // Start BFS from this vertex
            printf("\n");       // New line after each component
        }
    }
}

int main() {
    int v; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int graph[MAX_V][MAX_V] = {0}; // Adjacency matrix initialized to 0

    // Input edges until -1 -1 is encountered
    printf("Enter edges (u v), -1 -1 to end:\n");
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

/*
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
 */