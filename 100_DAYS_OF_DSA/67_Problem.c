// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int v;
    struct Node* next;
};

int stack[1000];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int u, bool visited[], struct Node* adj[]) {
    visited[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        if (!visited[temp->v]) {
            dfs(temp->v, visited, adj);
        }
        temp = temp->next;
    }

    // Push to stack after all neighbors are visited
    push(u);
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}