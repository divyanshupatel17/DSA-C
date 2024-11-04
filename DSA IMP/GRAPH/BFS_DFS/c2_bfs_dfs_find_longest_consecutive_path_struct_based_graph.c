#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum number of vertices in the graph
#define QUEUE_SIZE (MAX * MAX)  // Maximum size for the BFS queue

// Graph structure as an adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    Node* adjList[MAX];
    int numVertices;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;  // Initialize adjacency list
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;  // Add to the adjacency list
}

// Function to check if a character can be added to the path
bool canAddChar(char current, char next) {
    return next == current + 1;  // Check if next character is consecutive
}

// Depth-First Search to find the longest path with consecutive characters
int findLongestPathDFS(Graph* graph, char* characters, int vertex, char startChar, bool* visited) {
    visited[vertex] = true;  // Mark the current vertex as visited
    int longest = 1;  // Length of the path including the current vertex

    // Explore adjacent vertices
    Node* temp = graph->adjList[vertex];
    while (temp) {
        if (canAddChar(characters[vertex], characters[temp->vertex]) && !visited[temp->vertex]) {
            int pathLength = 1 + findLongestPathDFS(graph, characters, temp->vertex, startChar, visited);
            if (pathLength > longest) {
                longest = pathLength;  // Update longest path length
            }
        }
        temp = temp->next;  // Move to the next adjacent vertex
    }

    visited[vertex] = false;  // Backtrack: unmark the current vertex
    return longest;  // Return the longest path found
}

// BFS to find the longest path with consecutive characters
int longestPathBFS(Graph* graph, char* characters, char startChar) {
    int longest = 0;  // Initialize the longest path length
    int queue[QUEUE_SIZE];  // Queue for BFS
    int queueLength[QUEUE_SIZE];  // Queue for path lengths
    int front, rear;

    for (int i = 0; i < graph->numVertices; i++) {
        if (characters[i] == startChar) {
            front = 0;
            rear = 0;

            // Enqueue the starting position
            queue[rear] = i;  // Vertex index
            queueLength[rear++] = 1;  // Starting length is 1

            // Perform BFS
            while (front < rear) {
                int currentVertex = queue[front++];  // Dequeue the front vertex
                int currentLength = queueLength[front - 1];  // Dequeue the path length

                // Explore adjacent vertices
                Node* temp = graph->adjList[currentVertex];
                while (temp) {
                    if (canAddChar(characters[currentVertex], characters[temp->vertex])) {
                        queue[rear] = temp->vertex;  // Enqueue new position
                        queueLength[rear++] = currentLength + 1;  // Enqueue new path length

                        // Update the longest length found
                        if (currentLength + 1 > longest) {
                            longest = currentLength + 1;
                        }
                    }
                    temp = temp->next;  // Move to the next adjacent vertex
                }
            }
        }
    }

    return longest;  // Return the longest path found
}

int main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    // Ensure that the number of vertices does not exceed MAX
    if (vertices > MAX) {
        printf("The number of vertices exceeds the maximum allowed size of %d.\n", MAX);
        return 1;  // Exit if dimensions are invalid
    }

    Graph* graph = createGraph(vertices);  // Create the graph
    char characters[MAX];  // Character array for the vertices

    printf("Enter the characters for each vertex:\n");
    for (int i = 0; i < vertices; i++) {
        scanf(" %c", &characters[i]);  // Read characters for vertices
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (src dest) pairs:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);  // Read edges
        addEdge(graph, src, dest);  // Add edge to the graph
    }

    char startChar;
    printf("Enter the starting character: ");
    scanf(" %c", &startChar);

    // Finding the longest path using DFS
    bool visited[MAX] = {false};  // Visited array for DFS
    int resultDFS = 0;
    for (int i = 0; i < vertices; i++) {
        if (characters[i] == startChar) {
            int pathLen = findLongestPathDFS(graph, characters, i, startChar, visited);
            if (pathLen > resultDFS) {
                resultDFS = pathLen;  // Update longest path found by DFS
            }
        }
    }
    printf("DFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultDFS);

    // Finding the longest path using BFS
    int resultBFS = longestPathBFS(graph, characters, startChar);
    printf("BFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultBFS);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;  // Exit the program successfully
}
