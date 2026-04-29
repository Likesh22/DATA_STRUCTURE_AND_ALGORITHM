// Problem Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
/*
This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3
*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with a minimum distance of 'dist'
int canPlaceCows(int* stalls, int n, int k, int dist) {
    int count = 1; // Place the first cow
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= dist) {
            count++;
            lastPosition = stalls[i];
            if (count >= k) return 1; // All cows placed
        }
    }
    return 0;
}

int main() {
    int n, k;
    printf("Enter number of stalls and cows: ");
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        printf("Enter position of stall %d: ", i + 1);
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search for the maximum minimum distance
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;     // This distance works, try larger
            low = mid + 1;
        } else {
            high = mid - 1;    // Distance too large, try smaller
        }
    }

    printf("%d\n", result);

    return 0;
}