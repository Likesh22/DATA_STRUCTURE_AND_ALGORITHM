// Problem Statement -Using BFS or DFS, check if the entire graph is connected.
/*
Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int v;
    struct Node* next;
};

// DFS to mark all reachable nodes
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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Handle edge case: A graph with 0 nodes is technically connected, 
    // but 1 node is the standard base case.
    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

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

    // Start DFS from node 1
    dfs(1, adj, visited);

    // Check if any node was left behind
    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");

    return 0;
}