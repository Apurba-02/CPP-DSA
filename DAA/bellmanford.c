#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int vertices;

void printSolution(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void bellmanFord(int graph[vertices][vertices], int src)
{
    int dist[vertices];
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple shortest path from src
    // to any other vertex can have at most |V| - 1 edges
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (int u = 0; u < vertices; u++)
        {
            for (int v = 0; v < vertices; v++)
            {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative-weight cycles. The above step guarantees shortest
    // distances if graph doesn't contain negative weight cycle. If we get a shorter
    // path, then there is a cycle.
    for (int u = 0; u < vertices; u++)
    {
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                printf("Graph contains negative weight cycle\n");
                return; // If negative cycle is detected, simply return
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int edges, i, j, u, v, w;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);
    int graph[vertices][vertices];
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("\nEnter source, destination and weight:\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
    }
    
    bellmanFord(graph, 0);
    return 0;
}

