// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

// Helper: Insertion Sort for a Linked List
struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* sorted = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Put elements into different buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i]; // Index in bucket
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }

    // 3. Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Clean up memory
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");

    return 0;
}