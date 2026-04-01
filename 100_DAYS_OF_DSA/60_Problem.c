// Problem Statement: Check whether a given binary tree satisfies the Min-Heap property.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    // We only need to check internal nodes (nodes with at least one child)
    // The last internal node is at index (n/2 - 1)
    for (int i = 0; i <= (n / 2 - 1); i++) {
        
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check if Left Child exists and violates the property
        if (leftChild < n && arr[i] > arr[leftChild]) {
            return false;
        }

        // Check if Right Child exists and violates the property
        if (rightChild < n && arr[i] > arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter level-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}