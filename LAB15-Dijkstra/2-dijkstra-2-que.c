1.

Problem Statement



Implement a program to find the shortest path in a weighted graph, given a source vertex and a destination vertex, using DFS and Dijkstra''s algorithm.



The program should prompt the user to enter the number of vertices and edges in the graph, followed by the edges and their respective weights.



Finally, the program should ask the user for the source and destination vertices and print the shortest path and distance between them.

Input format :
The first line of input contains an integer n, denoting the number of vertices in the graph.

The second line of input contains an integer m, denoting the number of edges in the graph.

The next m lines each contain three space-separated integers u, v, and w denoting an edge between vertices u and v with weight w.

The next line of input contains an integer s, denoting the source vertex.

The last line of input contains an integer d, denoting the destination vertex.

Output format :
If there is no path from the source vertex to the destination vertex, the output displays "No path found".

If there is a path from the source vertex to the destination vertex:

The first line displays "Shortest path: " followed by the shortest path between them in the format "source -> vertex1 -> vertex2 -> ... -> destination".
The second line displays "Shortest distance: " followed by the shortest distance.


Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

1 ≤ m ≤ 100

0 ≤ u, v < n

0 ≤ w ≤ 100

0 ≤ s, d < n

Sample test cases :
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
Input 2 :
5
7
0 1 2
0 2 6
0 3 1
1 2 3
1 4 5
2 3 2
3 4 1
0
4
Output 2 :
Shortest path: 0 -> 3 -> 4
Shortest distance: 2
Input 3 :
3
2
0 1 5
1 2 3
0
2
Output 3 :
Shortest path: 0 -> 1 -> 2
Shortest distance: 8
Input 4 :
5
4
0 1 2
0 3 3
1 3 4
0 2 5
0
4
Output 4 :
No path found
Note :

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int findMin(int dist[], bool visited[], int v){
    int min=INT_MAX, minIdx;
    for(int i=0 ; i<v ; i++){
        if(dist[i] < min && !visited[i]){
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int graph[MAX][MAX], int v, int src, int dest){
    int dist[MAX];
    bool visited[MAX];
    int prev[MAX];
    
    for(int i=0 ; i<v ; i++){
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }
    
    visited[src] = true;
    dist[src] = 0;
    
    for(int count=0 ; count<v-1 ; count++){
        int x = findMin(dist,visited,v);
        visited[x] = true;
        
        for(int y=0 ; y<v ; y++){
            if(graph[x][y] && !visited[y] && dist[x]!=INT_MAX && dist[x]+graph[x][y] < dist[y]){
                dist[y] = graph[x][y]+dist[x];
                prev[y] = x;
            }
        }
    }
    
    if(dist[dest] == INT_MAX) {
        printf("No path found\n");
    } else {
        int path[MAX];
        int pathLen = 0;
        int currentIdx = dest;
        
        while(currentIdx != -1){
            path[pathLen++] = currentIdx;
            currentIdx = prev[currentIdx];
        }
        
        printf("Shortest path: %d",src);
        for(int i=pathLen-2 ; i>=0 ; i--){
            printf(" -> %d",path[i]);
        }
        printf("\nShortest distance: %d",dist[dest]);
    }
    
    
}

int main(){
    int v,e;
    scanf("%d",&v);
    scanf("%d",&e);
    int graph[MAX][MAX] = {0};
    
    for(int i=0 ; i<e ; i++){
        int a, b, w;
        scanf("%d %d %d",&a,&b,&w);
        graph[a][b] = w;
        graph[b][a] = w;
    }
    
    int src,dest;
    scanf("%d %d",&src,&dest);
    dijkstra(graph,v,src,dest);
    return 0;
}

Single File Programming Question
Problem Statement



Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.



Example



Input: 

source = 0, the graph is shown below.







Output: 

0 4 12 19 21 11 9 8 14



Explanation: 

The distance from 0 to 1 = 4.

The minimum distance from 0 to 2 = 12.

0->1->2

The minimum distance from 0 to 3 = 19.

0->1->2->3

The minimum distance from 0 to 4 = 21.

0->7->6->5->4

The minimum distance from 0 to 5 = 11.

0->7->6->5

The minimum distance from 0 to 6 = 9.

0->7->6

The minimum distance from 0 to 7 = 8.

0->7

The minimum distance from 0 to 8 = 14.

0->1->2->8

Input format :
The first line of input consists of the number of vertices, V in the graph.

The next lines of input consist of an adjacency matrix graph of size V x V representing the graph.

The last line of input consists of an integer representing the source vertex.



Refer to the sample input for formatting specifications.

Output format :
For each vertex v, print the line v distance, where v is the vertex index and distance is the minimum distance from the source vertex to v in the following format:



"Vertex" followed by a space and then use tab space after print "Distance from Source"

vertex1 followed by three tab spaces and then use a space after print source1.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ V ≤ 6

0 ≤ src < V

Edge weights are positive integers or zero.

Sample test cases :
Input 1 :
3
0 2 5
2 0 1
5 1 0
0
Output 1 :
Vertex 	Distance from Source
0			 0
1			 2
2			 3
Input 2 :
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
0
Output 2 :
Vertex 	Distance from Source
0			 0
1			 4
2			 12
3			 19
4			 21
5			 11
6			 9
7			 8
8			 14
Note : Result
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int findMinDist(int dist[], bool visited[], int v) {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int graph[MAX][MAX], int v, int src) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int x = findMinDist(dist, visited, v);
        visited[x] = true;

        for (int y = 0; y < v; y++) {
            if (!visited[y] && graph[x][y] && dist[x] != INT_MAX && dist[x] + graph[x][y] < dist[y]) {
                dist[y] = dist[x] + graph[x][y];
            }
        }
    }

    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < v; i++) {
        printf("%d\t\t\t %d\n", i, dist[i]);
    }
}

int main() {
    int v;
    scanf("%d", &v);
    int graph[MAX][MAX] = {0};
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int src;
    scanf("%d", &src);
    dijkstra(graph, v, src);
    return 0;
}

