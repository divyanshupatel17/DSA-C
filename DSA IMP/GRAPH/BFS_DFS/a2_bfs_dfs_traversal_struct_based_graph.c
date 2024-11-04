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

// DFS function for a single component
void dfs(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        if (graph->visited[temp->vertex] == 0) {
            dfs(graph, temp->vertex);
        }
        temp = temp->next;
    }
}

// BFS function for a single component
void bfs(struct Graph* graph, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    struct Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // DFS traversal for all components
    printf("DFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i);
            printf("\n");
        }
    }

    // Reset visited for BFS
    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;

    // BFS traversal for all components
    printf("BFS for all components:\n");
    for (int i = 0; i < vertices; i++) {
        if (!graph->visited[i]) {
            bfs(graph, i);
            printf("\n");
        }
    }

    return 0;
}
