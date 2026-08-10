#include <stdio.h>
	// Write your code here...
  int parent[100];
    int mincost = 0;
    int edge = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    while (edge < V - 1) {
        int min = INT_MAX;
        int a = -1, b = -1;

        // Find the minimum edge
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        // Find parent of a
        int u = a;
        while (parent[u] != u)
            u = parent[u];

        // Find parent of b
        int v = b;
        while (parent[v] != v)
            v = parent[v];

        // If they are in different sets, include the edge
        if (u != v) {
            printf("Edge %d:(%d, %d) cost:%d\n", edge, a, b, min);
            mincost += min;
            parent[v] = u;
            edge++;
        }

        // Remove the selected edge
        cost[a][b] = INT_MAX;
        cost[b][a] = INT_MAX;
    }

    printf("Minimum cost= %d\n", mincost);
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
