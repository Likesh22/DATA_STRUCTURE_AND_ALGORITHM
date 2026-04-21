// Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.
/*
Input:
- First line: integer n representing the number of vertices
- Next n lines: n space-separated integers representing the adjacency matrix of the graph
  (use -1 to indicate no direct edge between two vertices)

Output:
- Print the shortest distance matrix where the value at row i and column j represents the shortest distance from vertex i to vertex j

Example:
Input:
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1e9 // Using a large value that won't overflow on addition

void floydWarshall(int n, int dist[n][n]) {
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If vertex k is reachable from i and j is reachable from k
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 0;

    int dist[n][n];

    // Input the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            printf("Enter distance from vertex %d to vertex %d: ", i, j);
            scanf("%d", &val);
            if (val == -1 && i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = val;
            }
        }
    }

    floydWarshall(n, dist);

    // Output the shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}