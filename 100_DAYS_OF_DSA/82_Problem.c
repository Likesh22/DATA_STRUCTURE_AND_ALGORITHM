// Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
// Lower Bound: The index of the first element in the array that is greater than or equal to x
// Upper Bound: The index of the first element in the array that is strictly greater than x.

/*
Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)

Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5

*/

#include <stdio.h>

// Finds the first index i such that arr[i] >= x
int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is >= x

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;      // Potential answer
            high = mid - 1; // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Too small, look on the right
        }
    }
    return ans;
}

// Finds the first index i such that arr[i] > x
int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is > x

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;      // Potential answer
            high = mid - 1; // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Too small or equal, look on the right
        }
    }
    return ans;
}

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value x: ");
    scanf("%d", &x);

    printf("%d %d\n", findLowerBound(arr, n, x), findUpperBound(arr, n, x));

    return 0;
}