#include <stdio.h>
#include <stdbool.h>
#define MAX_V 7  // Maximum number of vertices

// Function to find the shortest path using BFS
void findPathBFS(int graph[MAX_V][MAX_V], int n, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V], queue[MAX_V];
    int front = 0, rear = 0;
    
    // Initialize BFS starting point
    visited[start] = true;
    parent[start] = -1;
    queue[rear++] = start;
    
    // BFS traversal
    while (front < rear) {
        int curr = queue[front++];
        
        if (curr == end) {  // Path found
            // Trace back the path from end to start using parent array
            int path[MAX_V], len = 0;
            for (int v = end; v != -1; v = parent[v]) path[len++] = v;
            
            // Print the path length and path vertices
            printf("Shortest path length (BFS): %d\n", len - 1);
            printf("Path (BFS): ");
            while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
            return;
        }
        
        // Explore adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                queue[rear++] = i;
            }
        }
    }
    printf("Not found\n");  // Path not found
}

// Recursive DFS helper function to find the shortest path
bool findPathDFSUtil(int graph[MAX_V][MAX_V], bool visited[], int parent[], int n, int curr, int end) {
    if (curr == end) return true;  // If destination is reached

    visited[curr] = true;  // Mark current as visited
    
    // Explore adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[curr][i] && !visited[i]) {
            parent[i] = curr;  // Set parent for path tracking
            if (findPathDFSUtil(graph, visited, parent, n, i, end))
                return true;  // Path found
        }
    }
    return false;  // No path found
}

// Function to find the shortest path using DFS
void findPathDFS(int graph[MAX_V][MAX_V], int n, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V];
    parent[start] = -1;  // Start has no parent

    // Check if a path exists using DFS
    if (findPathDFSUtil(graph, visited, parent, n, start, end)) {
        int path[MAX_V], len = 0;
        for (int v = end; v != -1; v = parent[v]) path[len++] = v;

        printf("Path length (DFS): %d\n", len - 1);
        printf("Path (DFS): ");
        while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
    } else {
        printf("Not found\n");  // Path not found
    }
}

int main() {
    int n, src, goal;
    scanf("%d", &n);  // Number of vertices
    
    if (n < 2 || n > MAX_V) { 
        printf("Not found\n"); 
        return 0; 
    }
    
    int graph[MAX_V][MAX_V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);  // Read adjacency matrix

    scanf("%d %d", &src, &goal);  // Read source and goal vertices
    if (src < 0 || src >= n || goal < 0 || goal >= n) { 
        printf("Not found\n"); 
        return 0; 
    }
    
    // Find path using BFS
    printf("Using BFS:\n");
    findPathBFS(graph, n, src, goal);

    // Find path using DFS
    printf("Using DFS:\n");
    findPathDFS(graph, n, src, goal);

    return 0;
}
