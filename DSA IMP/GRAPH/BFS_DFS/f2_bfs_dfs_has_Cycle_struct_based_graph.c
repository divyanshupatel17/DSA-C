#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Structure to represent an adjacency list
typedef struct Graph {
    Node* adjList[MAX];
    int V;
} Graph;

// Function to create a new graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to check for cycle using DFS
bool hasCycleDFS(Graph* graph, bool visited[], int curr, int parent) {
    visited[curr] = true;
    Node* temp = graph->adjList[curr];
    
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visited[adj]) {
            if (hasCycleDFS(graph, visited, adj, curr))
                return true;
        } else if (adj != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to check for cycle using BFS
bool hasCycleBFS(Graph* graph) {
    bool visited[MAX] = {false};
    int parent[MAX] = {-1};

    for (int start = 0; start < graph->V; start++) {
        if (!visited[start]) { // Start BFS from each unvisited vertex
            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;
            visited[start] = true;

            while (front != rear) {
                int curr = queue[front++];
                Node* temp = graph->adjList[curr];
                
                while (temp != NULL) {
                    int adj = temp->dest;
                    if (!visited[adj]) {
                        visited[adj] = true;
                        parent[adj] = curr;
                        queue[rear++] = adj;
                    } else if (adj != parent[curr]) {
                        return true;
                    }
                    temp = temp->next;
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

    // Create a graph
    Graph* graph = createGraph(V);

    // Input edges
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Initialize visited array for DFS
    bool visited[MAX] = {false};
    bool cycleFoundDFS = false;

    // Check for cycle using DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(graph, visited, i, -1)) {
                cycleFoundDFS = true;
                break;
            }
        }
    }

    // Check for cycle using BFS
    bool cycleFoundBFS = hasCycleBFS(graph);

    // Print results
    printf("Cycle Detected using DFS: %d\n", cycleFoundDFS ? 1 : 0);
    printf("Cycle Detected using BFS: %d\n", cycleFoundBFS ? 1 : 0);

    // Free memory
    for (int i = 0; i < V; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}
