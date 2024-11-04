#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_V 7  // Maximum number of vertices

// Graph structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_V];
} Graph;

// Queue structure for BFS
typedef struct {
    int data[MAX_V];
    int front, rear;
} Queue;

// Initialize a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize a graph with n vertices
Graph* createGraph(int n) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = n;
    for (int i = 0; i < n; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Add edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Initialize queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Add element to queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_V - 1) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = value;
}

// Remove element from queue
int dequeue(Queue* q) {
    if (q->front == -1) return -1;
    int item = q->data[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

// BFS function to find the shortest path
void findPathBFS(Graph* graph, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V], queue[MAX_V];
    Queue q;
    initQueue(&q);
    
    visited[start] = true;
    parent[start] = -1;
    enqueue(&q, start);
    
    // BFS traversal
    while (q.front != -1) {
        int curr = dequeue(&q);
        
        if (curr == end) {  // Path found
            int path[MAX_V], len = 0;
            for (int v = end; v != -1; v = parent[v])
                path[len++] = v;
            
            printf("Shortest path length (BFS): %d\n", len - 1);
            printf("Path (BFS): ");
            while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
            return;
        }
        
        for (Node* adj = graph->adjLists[curr]; adj; adj = adj->next) {
            int neighbor = adj->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                enqueue(&q, neighbor);
            }
        }
    }
    printf("Not found\n");
}

// Recursive DFS helper
bool findPathDFSUtil(Graph* graph, bool visited[], int parent[], int curr, int end) {
    if (curr == end) return true;
    visited[curr] = true;
    
    for (Node* adj = graph->adjLists[curr]; adj; adj = adj->next) {
        int neighbor = adj->vertex;
        if (!visited[neighbor]) {
            parent[neighbor] = curr;
            if (findPathDFSUtil(graph, visited, parent, neighbor, end))
                return true;
        }
    }
    return false;
}

// DFS function to find the shortest path
void findPathDFS(Graph* graph, int start, int end) {
    bool visited[MAX_V] = {0};
    int parent[MAX_V];
    parent[start] = -1;

    if (findPathDFSUtil(graph, visited, parent, start, end)) {
        int path[MAX_V], len = 0;
        for (int v = end; v != -1; v = parent[v])
            path[len++] = v;

        printf("Path length (DFS): %d\n", len - 1);
        printf("Path (DFS): ");
        while (len--) printf("%d%c", path[len], len ? ' ' : '\n');
    } else {
        printf("Not found\n");
    }
}

int main() {
    int n, src, goal;
    scanf("%d", &n);  // Number of vertices
    
    if (n < 2 || n > MAX_V) { 
        printf("Not found\n"); 
        return 0; 
    }

    Graph* graph = createGraph(n);
    
    // Read edges for adjacency list
    int edges[MAX_V][MAX_V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &edges[i][j]);
    
    // Construct the adjacency list from the matrix
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (edges[i][j]) addEdge(graph, i, j);
    
    scanf("%d %d", &src, &goal);  // Read source and goal vertices
    if (src < 0 || src >= n || goal < 0 || goal >= n) { 
        printf("Not found\n"); 
        return 0; 
    }
    
    // Find path using BFS
    printf("Using BFS:\n");
    findPathBFS(graph, src, goal);

    // Find path using DFS
    printf("Using DFS:\n");
    findPathDFS(graph, src, goal);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);

    return 0;
}
