#include <stdio.h>

#define MAX 100

// BFS function for a single component
void bfs(int graph[MAX][MAX], int visited[], int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// DFS function for a single component
void dfs(int graph[MAX][MAX], int visited[], int start, int v) {
    visited[start] = 1;
    printf("%d ", start);

    for(int j = 0; j < v; j++) {
        if(graph[start][j] == 1 && !visited[j]) {
            dfs(graph, visited, j, v);
        }
    }
}

int main() {
    int vertices, edges;
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int visited[MAX] = {0};     // Visited array for both BFS and DFS

    // Input number of vertices and edges
    scanf("%d %d", &vertices, &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;  // For undirected graph
    }

    // DFS traversal for all components
    printf("DFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, vertices);
            printf("\n");
        }
    }

    // Reset visited for BFS
    for (int i = 0; i < vertices; i++) visited[i] = 0;


    // BFS traversal for all components
    /* if you start from any particular vertex
    int start;
    scanf("%d",&start);
    bfs(graph,visited,start,v);
    */

    // disconnected graph
    printf("BFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            bfs(graph, visited, i, vertices);
            printf("\n");
        }
    }

    return 0;
}

/*
input : 

6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0

*/