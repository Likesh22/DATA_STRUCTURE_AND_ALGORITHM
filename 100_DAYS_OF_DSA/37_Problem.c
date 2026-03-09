// Problem Statement:Implement a Priority Queue using an array. An element with smaller value has higher priority.

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

void insert(int val) {
    if (size == MAX) return;
    
    heap[size] = val;
    int curr = size;
    size++;

    // Bubble Up
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

int deleteMin() {
    if (size == 0) return -1;

    int minVal = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Bubble Down
    int curr = 0;
    while (2 * curr + 1 < size) {
        int smallest = 2 * curr + 1; // Left child
        int right = 2 * curr + 2;    // Right child

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (heap[curr] <= heap[smallest]) break;

        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }

    return minVal;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    printf("Enter the number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        printf("Enter operation (insert/delete/peek): ");
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}