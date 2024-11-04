#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
void bfs(int adj[MAX][MAX], int V, int s) 
{
    int q[MAX], front = 0, rear = 0;    
    bool visited[MAX] = { false };
    visited[s] = true;
    q[rear++] = s;
    while (front < rear) 
    {
        int curr = q[front++];
        printf("%d ", curr);
        
        for (int i = 0; i < V; i++) 
        {
            if (adj[curr][i] == 1 && !visited[i]) 
            {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v) 
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int adj[MAX][MAX] = {0};
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++) 
    {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < V && v >= 0 && v < V) 
        {
            addEdge(adj, u, v);
        } else {
            printf("Invalid edge! Vertex indices must be between 0 and %d.\n", V - 1);
            i--;
        }
    }
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    if (startVertex >= 0 && startVertex < V) 
    {
        printf("BFS starting from vertex %d:\n", startVertex);
        bfs(adj, V, startVertex);
    } else 
    {
        printf("Invalid starting vertex! Must be between 0 and %d.\n", V - 1);
    }
    return 0;
}

