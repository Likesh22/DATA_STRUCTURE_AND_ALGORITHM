// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
/*
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, isDirected;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // Dynamically allocate n x n matrix and initialize to 0
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Enter %d pairs of edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Adjust for 0-indexed or 1-indexed input
        // Assuming 0-indexed here; if 1-indexed, use u-1 and v-1
        if (u < n && v < n) {
            matrix[u][v] = 1;
            if (!isDirected) {
                matrix[v][u] = 1; // Symmetric for undirected
            }
        } else {
            printf("Error: Vertex index out of bounds (0 to %d).\n", n - 1);
            i--; // Redo this input
        }
    }

    printMatrix(matrix, n);

    // Free memory
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}