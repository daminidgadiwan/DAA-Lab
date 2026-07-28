#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

    int parent[V];

    // Initialize parent array
    for(int i = 0; i < V; i++)
        parent[i] = i;

    int edgeCount = 0;
    int minCost = 0;

    while(edgeCount < V - 1) {

        int min = INT_MAX;
        int u = -1, v = -1;

        // Find the minimum edge
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find parent of u
        int i = u;
        while(parent[i] != i)
            i = parent[i];

        // Find parent of v
        int j = v;
        while(parent[j] != j)
            j = parent[j];

        // If no cycle, include the edge
        if(i != j) {
            parent[j] = i;
            printf("Edge %d:(%d, %d) cost:%d\n", edgeCount, u, v, min);
            minCost += min;
            edgeCount++;
        }

        // Remove the processed edge
        cost[u][v] = INT_MAX;
        cost[v][u] = INT_MAX;
    }

    printf("Minimum cost= %d\n", minCost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
