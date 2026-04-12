// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
/*
Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e9 // Using a large value to prevent overflow during addition

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // 1. Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 2. Check for negative weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    // 3. Output results
    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Vertex \t Distance from Source %d\n", src);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) printf("%d \t INF\n", i);
            else printf("%d \t %d\n", i, dist[i]);
        }
    }

    free(dist);
}

int main() {
    int n, m, src;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    free(edges);
    return 0;
}