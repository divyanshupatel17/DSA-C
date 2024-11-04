#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure with adjacency list and visited array
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    int visited[MAX];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a specified number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add an undirected edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS function to check if the graph is bipartite
int isBipartiteBFS(struct Graph* graph, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, which means "uncolored"
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];

        // Check for a self-loop
        if (graph->adjLists[u] != NULL) {
            struct Node* temp = graph->adjLists[u];
            while (temp) {
                if (temp->vertex == u) return 0;  // Self-loop found
                temp = temp->next;
            }
        }

        // Explore all adjacent vertices
        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int adj = temp->vertex;
            if (color[adj] == -1) {  // If the adjacent vertex is not colored
                color[adj] = 1 - color[u];  // Assign opposite color
                queue[rear++] = adj;
            } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
                return 0;  // Graph is not bipartite
            }
            temp = temp->next;
        }
    }
    return 1;  // Graph is bipartite
}

// Helper function for DFS
int dfsCheck(struct Graph* graph, int color[], int u) {
    for (struct Node* temp = graph->adjLists[u]; temp != NULL; temp = temp->next) {
        int adj = temp->vertex;
        if (color[adj] == -1) {  // If the adjacent vertex is not colored
            color[adj] = 1 - color[u];  // Assign opposite color
            if (!dfsCheck(graph, color, adj)) {
                return 0;  // Graph is not bipartite
            }
        } else if (color[adj] == color[u]) {  // If adjacent vertices have the same color
            return 0;  // Graph is not bipartite
        }
    }
    return 1;  // Continue checking
}

// Function to check if the graph is bipartite using DFS
int isBipartiteDFS(struct Graph* graph, int start) {
    int color[MAX];
    // Initialize all vertices with color -1, meaning "uncolored"
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }

    color[start] = 1;  // Start coloring the starting vertex with color 1
    return dfsCheck(graph, color, start);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int start;
    printf("Enter the starting vertex for bipartite check: ");
    scanf("%d", &start);

    // Check if the graph is bipartite using BFS
    if (isBipartiteBFS(graph, start)) {
        printf("Yes, the given graph is Bipartite (BFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (BFS check)\n");
    }

    // Reset visited for DFS
    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;

    // Check if the graph is bipartite using DFS
    if (isBipartiteDFS(graph, start)) {
        printf("Yes, the given graph is Bipartite (DFS check)\n");
    } else {
        printf("No, the given graph is not Bipartite (DFS check)\n");
    }

    return 0;
}
