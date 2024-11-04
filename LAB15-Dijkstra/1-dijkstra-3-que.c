Problem No.	Problem Statement	                                Operation	    Method Used                                    	 Alternative Methods

1	        Find shortest path between routers in a network	    Shortest path	Dijkstra's Algorithm	                         Bellman-Ford for negative weights
2       	Shortest path in a directed graph of cities	        Shortest path	Dijkstra's Algorithm	                         Floyd-Warshall for all-pairs
3	        Shortest path between cities in unweighted graph	Shortest path   Dijkstra's Algorithm(with backtrack for path)    BFS	DFS for simple path finding

1.
Problem Statement



Define a program to find the shortest path between two routers in a network. The network is represented as a collection of routers connected by links, each link having a certain weight. 



Write a program that takes the number of routers, the number of links, and the details of connections between routers as input.



The program should then find and print the shortest path from a specified source router to a destination router using Dijkstra's algorithm.

Input format :
The first line contains an integer N, representing the number of routers.

The second line contains an integer M, representing the number of links.

The next M lines each contain three space-separated integers: r1, r2, and w, representing a link between routers r1 and r2 with the given w.

The next line contains an integer s, representing the source router.

The last line contains an integer d, representing the destination router.

Output format :
The output prints the shortest distances from the source router to all other routers in the network.

Each line should contain two integers separated by a space, representing the router and its distance from the source.



Refer to the sample output for the formatting specifications.

Code constraints :
2 ≤ N ≤ 8

1≤ M ≤ 12

0 ≤ w ≤ 7

Sample test cases :
Input 1 :
4
5
0 1 1
0 2 3
1 2 1
1 3 4
2 3 1
0
3
Output 1 :
0 0
1 1
2 2
3 3
Input 2 :
3
3
0 1 2
0 2 4
1 2 1
0
2
Output 2 :
0 0
1 2
2 3
Note :

;
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 8 // Maximum number of routers

int findMinDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < n; i++)
        if (visited[i] == false && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];       // dist[i] will hold the shortest distance from src to i
    bool visited[MAX];    // visited[i] will be true if router i is finalized

    // Initialize distances to all routers as infinite and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source router from itself is always 0
    dist[src] = 0;

    // Find shortest path for all routers
    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(dist, visited, n); // Select router with minimum distance
        visited[u] = true; // Mark the picked router as processed

        // Update dist[] of the adjacent routers of the picked router
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the distances
    for (int i = 0; i < n; i++)
        printf("%d %d\n", i, dist[i]);
}

int main() {
    int n, m; // Number of routers and links
    scanf("%d", &n);
    scanf("%d", &m);

    int graph[MAX][MAX] = {0}; // Adjacency matrix for the network

    // Reading the router links
    for (int i = 0; i < m; i++) {
        int r1, r2, w;
        scanf("%d %d %d", &r1, &r2, &w);
        graph[r1][r2] = w;
        graph[r2][r1] = w; // Since the network is bidirectional
    }

    int src, dest;
    scanf("%d", &src);
    scanf("%d", &dest);    // no need 

    // Execute Dijkstra's algorithm
    dijkstra(graph, n, src);

    return 0;
}

2.
Problem Statement



You are provided with a map of cities represented as vertices and roads connecting these cities represented as edges with associated weights. The task is to find the shortest path from a specified starting city to all other cities using Dijkstra's algorithm.



Note: The given graph is a directed graph.

Input format :
The first line contains two integers n and m, separated by a space where n represents the number of cities, and m represents the number of roads.

The next m lines describe the roads. Each line contains three integers, u, v, and w, separated by spaces. u is the starting city, v is the ending city, and w is the length of the road.

The last line contains an integer S, which is the starting city.

Output format :
The output consists of n-1 lines.



Each line contains one of the following two types of output:

If there is a reachable path from the starting city to the corresponding city, print: "City x: y units", where x is the city number and y is the shortest distance from the source city to city x.

If there is no path from the starting city to the corresponding city, print: "City x: Not reachable", where x is the city number.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ n ≤ 100

0 ≤ m ≤ (n) * (n - 1)

0 ≤ u, v < n

0 ≤ w ≤ INT_MAX (Maximum value of integer)

Sample test cases :
Input 1 :
4 4
0 1 5
0 2 3
1 3 2
2 3 3
1
Output 1 :
City 0: Not reachable
City 2: Not reachable
City 3: 2 units
Input 2 :
5 7
0 1 2
0 2 4
1 3 5
2 3 1
2 4 7
3 4 3
4 0 2
0
Output 2 :
City 1: 2 units
City 2: 4 units
City 3: 5 units
City 4: 8 units
Note :
'
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int findMinDistance(int dist[], bool visited[], int n){
    int min = INT_MAX, minIdx;
    for(int i=0 ; i<n ; i++){
        if(dist[i] < min && visited[i]==false){
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int graph[MAX][MAX], int n,int src){
    bool visited[MAX];
    int dist[MAX];
    
    for(int i=0 ; i<n ; i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    
    dist[src] = 0;
    
    for(int i=0 ; i<n-1 ; i++){
        int u = findMinDistance(dist,visited,n);
        visited[u] = true;
        
        for(int v=0 ; v<n ; v++){
            if(visited[v]==false && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    for(int i=0 ; i<n ; i++){
        if(i!=src){
            int d = dist[i];
            if(d!=INT_MAX) printf("City %d: %d units\n",i,d);
            else printf("City %d: Not reachable\n",i);
        }
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    
    int graph[MAX][MAX] = {0};
    for(int i=0 ; i<m ; i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        graph[a][b] = w;
        // graph[b][a] = w;         as this is a directed graph , given in que
    }
    
    int src;
    scanf("%d",&src);
    dijkstra(graph,n,src);
    return 0;
}

3
.Problem Statement



Given a network of cities represented as an unweighted graph, find the shortest path between a source city and a destination city in terms of the minimum number of roads to be traversed. Implement a program that utilizes the Dijkstra algorithm to solve this problem.



The program should take the city network, source city, and destination city as inputs, and provide the shortest path length and the sequence of cities to be visited along the path as outputs.

Input format :
The first line contains an integer n, representing the number of cities in the network.

The second line contains an integer m, representing the number of roads in the city network.

The following m lines contain pairs of integers u and v, representing a road between cities u and v.

The next line contains an integer s, representing the source city.

The last line contains an integer d, representing the destination city.

Output format :
The first line displays "Shortest path length: " followed by the shortest path length between the source and destination cities.

The second line displays "Path: " followed by the sequence of indices of the cities separated by a space, representing the shortest path from the source to the destination.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

0 ≤ m ≤ n * (n - 1) / 2

0 ≤ u, v < n

0 ≤ s, d < n

Sample test cases :
Input 1 :
8
10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
0 
7
Output 1 :
Shortest path length: 2
Path: 0 3 7 
Input 2 :
8
10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
2 
6
Output 2 :
Shortest path length: 5
Path: 2 1 0 3 4 6 
Note :

// Using Dijkstras
#include <limits.h>
#include <stdio.h>

const int MAX_CITIES = 100;

// Function to find minimum distance index
int minDistance(int distances[], int visited[], int cities) {
    int minIndex = -1;
    int min = INT_MAX;

    for (int i = 0; i < cities; i++) {
        if (!visited[i] && distances[i] < min) {
            min = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's algorithm function
void dijkstra(int graph[][MAX_CITIES], int source, int destination, int cities) {
    int distances[MAX_CITIES];
    int previous[MAX_CITIES];
    int visited[MAX_CITIES];

    // Initialize distances, previous and visited
    for (int i = 0; i < cities; i++) {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visited[i] = 0;
    }

    distances[source] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < cities; i++) {
        int minIndex = minDistance(distances, visited, cities);
        visited[minIndex] = 1;

        // Update distances
        for (int j = 0; j < cities; j++) {
            if (graph[minIndex][j] && distances[minIndex] + graph[minIndex][j] < distances[j]) {
                distances[j] = distances[minIndex] + graph[minIndex][j];
                previous[j] = minIndex;
            }
        }
    }

    // Print shortest path
    printf("Shortest path length: %d\n", distances[destination]);

    // Backtrack path
    int path[MAX_CITIES];
    int pathLength = 0;
    int currentIndex = destination;

    while (currentIndex != -1) {
        path[pathLength++] = currentIndex;
        currentIndex = previous[currentIndex];
    }

    printf("Path: ");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    int cities, roads, source, destination;

    scanf("%d %d", &cities, &roads);

    int graph[MAX_CITIES][MAX_CITIES];

    // Initialize graph
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            graph[i][j] = 0;
        }
    }

    // Input roads
    for (int i = 0; i < roads; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;  // Undirected graph
    }

    scanf("%d %d", &source, &destination);

    dijkstra(graph, source, destination, cities);

    return 0;
}

// USING BFS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// Function to perform BFS and find the shortest path in an unweighted graph
void bfsShortestPath(int graph[MAX][MAX], int n, int src, int dest) {
    int dist[MAX];       // Array to store shortest distance from src to each vertex
    int parent[MAX];     // Array to store the path
    bool visited[MAX];   // Array to mark visited vertices

    // Initialize distances as infinity and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Queue for BFS
    int queue[MAX];
    int front = 0, rear = 0;

    // Initialize BFS with the source node
    dist[src] = 0;
    visited[src] = true;
    queue[rear++] = src;

    // Perform BFS
    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[rear++] = v;

                // Stop BFS if we reach the destination
                if (v == dest) break;
            }
        }
    }

    // Output the shortest path length and path from src to dest
    if (dist[dest] == INT_MAX) {
        printf("Destination is not reachable from the source.\n");
    } else {
        printf("Shortest path length: %d\n", dist[dest]);

        // Trace the path from dest back to src using parent array
        int path[MAX];
        int pathLength = 0;
        for (int v = dest; v != -1; v = parent[v]) {
            path[pathLength++] = v;
        }

        printf("Path: ");
        for (int i = pathLength - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    // Read the edges (roads between cities)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // Since the graph is unweighted, use 1 to indicate an edge
        graph[v][u] = 1;  // The graph is undirected
    }

    int src, dest;
    scanf("%d %d", &src, &dest);

    // Run BFS to find the shortest path
    bfsShortestPath(graph, n, src, dest);

    return 0;
}

