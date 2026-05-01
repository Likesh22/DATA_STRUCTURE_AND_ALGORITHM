// Problem Statement Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
/*
Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/

#include <stdio.h>

// Helper to check if it's possible to paint all boards within 'limit' time
int isPossible(int* boards, int n, int k, long long limit) {
    int paintersUsed = 1;
    long long currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than the limit, it's impossible
        if (boards[i] > limit) return 0;

        if (currentTime + boards[i] > limit) {
            // Assign to a new painter
            paintersUsed++;
            currentTime = boards[i];
            if (paintersUsed > k) return 0;
        } else {
            currentTime += boards[i];
        }
    }
    return 1;
}

long long getMinTime(int* boards, int n, int k) {
    long long low = 0, high = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;       // Try to find an even smaller maximum time
            high = mid - 1;
        } else {
            low = mid + 1;   // Need more time to accommodate k painters
        }
    }
    return ans;
}

int main() {
    int n, k;
    printf("Enter number of boards and painters: ");
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    for (int i = 0; i < n; i++) {
        printf("Enter length of board %d: ", i + 1);
        scanf("%d", &boards[i]);
    }

    printf("%lld\n", getMinTime(boards, n, k));

    return 0;

}