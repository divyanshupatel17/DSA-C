#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// Function to check for cycle using DFS
bool hasCycleDFS(int graph[MAX][MAX], bool visited[], int V, int curr, int parent) {
    visited[curr] = true;
    
    for (int i = 0; i < V; i++) {
        if (graph[curr][i]) { // If there is an edge
            if (!visited[i]) { // If not visited, recursively visit it
                if (hasCycleDFS(graph, visited, V, i, curr))
                    return true;
            } else if (i != parent) { // If visited and not parent, cycle exists
                return true;
            }
        }
    }
    return false;
}

// Function to check for cycle using BFS
bool hasCycleBFS(int graph[MAX][MAX], int V) {
    bool visited[MAX] = {false};
    int parent[MAX] = {-1};

    for (int start = 0; start < V; start++) {
        if (!visited[start]) { // Start BFS from each unvisited vertex
            visited[start] = true;
            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;

            while (front != rear) {
                int curr = queue[front++];
                
                for (int i = 0; i < V; i++) {
                    if (graph[curr][i]) { // If there is an edge
                        if (!visited[i]) { // If not visited, enqueue it
                            visited[i] = true;
                            parent[i] = curr;
                            queue[rear++] = i;
                        } else if (i != parent[curr]) { // If visited and not parent, cycle exists
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    int graph[MAX][MAX] = {0};

    // Input edges
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        // Add edge to adjacency matrix (undirected)
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    // Initialize visited array for DFS
    bool visited[MAX] = {false};
    bool cycleFoundDFS = false;

    // Check for cycle using DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(graph, visited, V, i, -1)) {
                cycleFoundDFS = true;
                break;
            }
        }
    }

    // Check for cycle using BFS
    bool cycleFoundBFS = hasCycleBFS(graph, V);

    // Print results
    printf("Cycle Detected using DFS: %d\n", cycleFoundDFS ? 1 : 0);
    printf("Cycle Detected using BFS: %d\n", cycleFoundBFS ? 1 : 0);

    return 0;
}

/*
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
 */