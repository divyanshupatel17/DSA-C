#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

bool hasCycleDFS(int graph[MAX][MAX], int visited[], int V,int curr,int parent){
    visited[curr] = 1;

    for(int i=0 ; i<V ; i++){
        if(graph[curr][i] == 1){
            if(!visited[i]){
                if(hasCycleDFS(graph,visited,V,i,curr)){
                    return true;
                }
            }
            else if(i != parent){
                return true;
            }
        }
    }
    return false;
}

bool hasCycleBFS(int graph[MAX][MAX], int V){
    bool visited[MAX] = {false};
    int parent[MAX] = {-1};

    for(int start = 0 ; start < V ; start++){
        if(!visited[start]){
            visited[start] = true;
            int queue[MAX], front=0, rear=0;
            queue[rear++] = start;

            while(front < rear){
                int curr = queue[front++];

                for(int i=0 ; i<V ; i++){
                    if(graph[curr][i]){
                        if(!visited){
                            visited[i] = true;
                            queue[rear++] = i;
                            parent[i] = curr;
                        } else if(i != parent[curr]){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int V,E;
    scanf("%d %d",&V,&E);

    int graph[MAX][MAX] = {0};

    for(int i=0 ; i<E ; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int visited[MAX] = {0};
    bool cycleFoundDFS = false;

    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            if(hasCycleDFS(graph,visited,V,i,-1)){
                cycleFoundDFS = true;
                break;
            }
        }
    }

    if(cycleFoundDFS) printf("Cycle found using DFS\n");
    else              printf("Cycle not found using DFS\n");

    bool cycleFoundBFS = hasCycleBFS(graph,V);

    if(cycleFoundBFS) printf("Cycle found using BFS\n");
    else              printf("Cycle not found using BFS\n");
    return 0;
}