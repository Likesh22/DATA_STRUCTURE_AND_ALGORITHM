// Problem Statement Find shortest distances from source vertex in a weighted graph with non-negative weights.
/*
Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

struct Edge {
    int to, weight;
    struct Edge* next;
};

// --- Heap Functions ---
MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    h->size = 0;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* h, int node, int dist) {
    int i = h->size++;
    h->data[i].node = node;
    h->data[i].dist = dist;
    while (i != 0 && h->data[(i - 1) / 2].dist > h->data[i].dist) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < h->size && h->data[right].dist < h->data[left].dist) smallest = right;
        if (h->data[i].dist <= h->data[smallest].dist) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return root;
}

// --- Main Algorithm ---
void dijkstra(int n, struct Edge* adj[], int source) {
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    MinHeap* pq = createHeap(10000); // Adjust based on edge count
    push(pq, source, 0);

    while (pq->size > 0) {
        HeapNode current = pop(pq);
        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) continue;

        struct Edge* edge = adj[u];
        while (edge != NULL) {
            int v = edge->to;
            int w = edge->weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
            edge = edge->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    struct Edge* adj[n + 1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        struct Edge* e1 = (struct Edge*)malloc(sizeof(struct Edge));
        e1->to = v; e1->weight = w; e1->next = adj[u]; adj[u] = e1;
        
        struct Edge* e2 = (struct Edge*)malloc(sizeof(struct Edge));
        e2->to = u; e2->weight = w; e2->next = adj[v]; adj[v] = e2;
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    dijkstra(n, adj, source);

    return 0;
}