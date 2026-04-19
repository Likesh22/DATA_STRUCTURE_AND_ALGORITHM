// Problem Statement - Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
/*
Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int to, weight;
    struct Edge* next;
};

void addEdge(struct Edge* adj[], int u, int v, int w) {
    struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->to = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge* adj[n + 1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    int key[n + 1];
    bool visited[n + 1];
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        // Find the node with the minimum key value
        int u = -1, minKey = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break; // Graph is disconnected

        visited[u] = true;
        totalWeight += minKey;

        // Relax edges
        struct Edge* curr = adj[u];
        while (curr != NULL) {
            int v = curr->to;
            int w = curr->weight;
            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }
            curr = curr->next;
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}