// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v, int inDegree[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    inDegree[v]++; // Increment in-degree of destination
}

void topologicalSort(int n, struct Node* adj[], int inDegree[]) {
    int queue[n];
    int head = 0, tail = 0;
    int result[n];
    int count = 0;

    // 1. Push all nodes with 0 in-degree to queue
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    // 2. BFS Process
    while (head < tail) {
        int u = queue[head++];
        result[count++] = u;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            inDegree[v]--; // "Remove" the edge u -> v
            
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
            temp = temp->next;
        }
    }

    // 3. Final Output
    if (count != n) {
        printf("The graph contains a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) printf("%d ", result[i]);
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n];
    int* inDegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, inDegree);
    }

    topologicalSort(n, adj, inDegree);

    return 0;
}