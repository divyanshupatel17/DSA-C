#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// Function to find the unvisited vertex with the minimum distance
int findMin(int dist[], bool visited[], int v) {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < v; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

// Dijkstra's algorithm to find shortest path from source to destination
void dijkstra(int graph[MAX][MAX], int v, int src, int dest) {
    int dist[MAX], prev[MAX];
    bool visited[MAX] = { false };
    
    // Initialize distances and previous vertices
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;
    
    // Dijkstra's algorithm main loop
    for (int count = 0; count < v - 1; count++) {
        int x = findMin(dist, visited, v);
        visited[x] = true;
        
        for (int y = 0; y < v; y++) {
            if (graph[x][y] && !visited[y] && dist[x] != INT_MAX && dist[x] + graph[x][y] < dist[y]) {
                dist[y] = dist[x] + graph[x][y];
                prev[y] = x;
            }
        }
    }
    
    // Check if destination is reachable
    if (dist[dest] == INT_MAX) {
        printf("No path found\n");
    } else {
        // Backtrack to find path from destination to source
        int path[MAX], pathLen = 0;
        for (int idx = dest; idx != -1; idx = prev[idx]) {
            path[pathLen++] = idx;
        }
        
        // Print shortest path
        printf("Shortest path: %d", src);
        for (int i = pathLen - 2; i >= 0; i--) {
            printf(" -> %d", path[i]);
        }
        printf("\nShortest distance: %d\n", dist[dest]);
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e); // Number of vertices and edges
    
    int graph[MAX][MAX] = {0}; // Initialize graph with 0s
    
    // Input edges
    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a][b] = w;
        graph[b][a] = w;
    }
    
    int src, dest;
    scanf("%d %d", &src, &dest); // Input source and destination
    dijkstra(graph, v, src, dest);
    
    return 0;
}

/*
Input 1 :
4
5
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
0
3
Output 1 :
Shortest path: 0 -> 1 -> 2 -> 3
Shortest distance: 6
*/