// Problem Statement -Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

/*
Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

// Simple hash function to handle negative sums
int hash(int key) {
    int h = key % HASH_SIZE;
    return (h < 0) ? h + HASH_SIZE : h;
}

void insert(int sum, int index) {
    int h = hash(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int find(int sum) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum) return temp->index;
        temp = temp->next;
    }
    return -2; // Not found
}

int maxLen(int arr[], int n) {
    int max_len = 0;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        if (current_sum == 0) {
            max_len = i + 1;
        } else {
            int prev_index = find(current_sum);
            if (prev_index != -2) {
                int len = i - prev_index;
                if (len > max_len) max_len = len;
            } else {
                insert(current_sum, i);
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("%d\n", maxLen(arr, n));
    return 0;
}