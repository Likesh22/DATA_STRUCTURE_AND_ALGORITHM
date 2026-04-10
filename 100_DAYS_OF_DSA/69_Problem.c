// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure for Adjacency List
struct Edge {
    int to, weight;
    struct Edge* next;
};

// Structure for Min-Heap Node
struct HeapNode {
    int v, dist;
};

// Global Heap for Priority Queue
struct HeapNode heap[10000];
int heapSize = 0;

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a; *a = *b; *b = t;
}

void push(int v, int d) {
    heap[heapSize] = (struct HeapNode){v, d};
    int i = heapSize++;
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < heapSize && heap[right].dist < heap[left].dist) smallest = right;
        if (heap[i].dist <= heap[smallest].dist) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return root;
}

void addEdge(struct Edge** adj, int u, int v, int w) {
    struct Edge* edge = malloc(sizeof(struct Edge));
    edge->to = v;
    edge->weight = w;
    edge->next = adj[u];
    adj[u] = edge;
}

void dijkstra(int n, struct Edge** adj, int start) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[start] = 0;

    push(start, 0);

    while (heapSize > 0) {
        struct HeapNode curr = pop();
        int u = curr.v;

        if (curr.dist > dist[u]) continue;

        struct Edge* e = adj[u];
        while (e) {
            if (dist[u] + e->weight < dist[e->to]) {
                dist[e->to] = dist[u] + e->weight;
                push(e->to, dist[e->to]);
            }
            e = e->next;
        }
    }

    printf("Vertex \t Distance from Source %d\n", start);
    for (int i = 0; i < n; i++) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int n, m, start;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge** adj = calloc(n, sizeof(struct Edge*));

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // Use this line for undirected graphs
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    dijkstra(n, adj, start);

    return 0;
}