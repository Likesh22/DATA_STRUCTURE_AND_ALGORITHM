// Problem Statement Using DFS or BFS, count number of connected components.
/*
Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int v;
    struct Node* next;
};

// DFS to visit all nodes in a component
void dfs(int u, struct Node* adj[], bool visited[]) {
    visited[u] = true;
    struct Node* temp = adj[u];
    while (temp != NULL) {
        if (!visited[temp->v]) {
            dfs(temp->v, adj, visited);
        }
        temp = temp->next;
    }
}

void addEdge(struct Node* adj[], int u, int v) {
    // Add edge u -> v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    
    // Add edge v -> u (undirected)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n + 1];
    bool visited[n + 1];
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int componentCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            componentCount++;
            dfs(i, adj, visited);
        }
    }

    printf("%d\n", componentCount);

    return 0;
}