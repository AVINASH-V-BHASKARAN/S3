#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int dest;
    struct Node* next;
};

struct AdjList 
{
    struct Node* head;
};

struct Node* createNode(int dest) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct AdjList adj[], int s, int t) 
{
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;
    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

void DFSRec(struct AdjList adj[], int visited[], int s) 
{
    visited[s] = 1;
    printf("%d ", s);
    struct Node* current = adj[s].head;
    while (current != NULL) {
        int dest = current->dest;
        if (!visited[dest]) {
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}

void DFS(struct AdjList adj[], int V) 
{
    int* visited = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) 
    {
        if (visited[i] == 0) 
        {
            DFSRec(adj, visited, i);
        }
    }
    free(visited);
}

int main() 
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    struct AdjList* adj = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) 
    {
        adj[i].head = NULL;
    }
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
    printf("Complete DFS of the graph:\n");
    DFS(adj, V);
    for (int i = 0; i < V; i++) 
    {
        struct Node* current = adj[i].head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adj);
    return 0;
}

