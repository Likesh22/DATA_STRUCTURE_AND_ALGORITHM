// Problem: Detect cycle in directed graph using DFS and recursion stack.
// Output:- YES if cycle exists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int v;
    struct Node* next;
};

// Function to add a directed edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

bool dfs(int u, bool visited[], bool recStack[], struct Node* adj[]) {
    // Mark current node as visited and add to recursion stack
    visited[u] = true;
    recStack[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->v;

        // If neighbor is not visited, recurse
        if (!visited[v]) {
            if (dfs(v, visited, recStack, adj)) return true;
        } 
        // If neighbor is already in the current recursion stack, cycle found
        else if (recStack[v]) {
            return true;
        }
        temp = temp->next;
    }

    // Remove the node from recursion stack before backtracking
    recStack[u] = false;
    return false;
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < n && v < n) addEdge(adj, u, v);
    }

    bool hasCycle = false;
    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool* recStack = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    // Clean up
    free(visited);
    free(recStack);
    return 0;
}