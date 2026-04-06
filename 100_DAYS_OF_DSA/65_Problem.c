// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
// Output:- YES or NO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int v;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

bool dfs(int u, int parent, bool visited[], struct Node* adj[]) {
    visited[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->v;

        if (!visited[v]) {
            if (dfs(v, u, visited, adj)) return true;
        } 
        // If neighbor is visited and is NOT the parent, it's a back-edge (cycle)
        else if (v != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    bool hasCycle = false;
    bool* visited = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}