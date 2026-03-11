// Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.
/*
Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restores heap property by moving element up
void bubbleUp(int idx) {
    while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        swap(&heap[(idx - 1) / 2], &heap[idx]);
        idx = (idx - 1) / 2;
    }
}

// Restores heap property by moving element down
void bubbleDown(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        bubbleDown(smallest);
    }
}

void insert(int x) {
    if (size >= MAX) return;
    heap[size] = x;
    bubbleUp(size);
    size++;
}

int extractMin() {
    if (size <= 0) return -1;
    int minVal = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return minVal;
}

int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int main() {
    int n;
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}