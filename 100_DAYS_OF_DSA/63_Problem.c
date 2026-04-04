// Problem: Perform DFS starting from a given source vertex using recursion.
/*
Input:
- n
- adjacency list
- starting vertex s
Output:
- DFS traversal order
*/

#include <stdio.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int n;

// DFS function
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}