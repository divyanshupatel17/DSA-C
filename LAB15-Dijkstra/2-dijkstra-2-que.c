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