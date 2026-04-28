// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
/*
Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8
*/

#include <stdio.h>

int findIntegerSqrt(int n) {
    // Base cases
    if (n == 0 || n == 1) return n;

    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Using division to avoid integer overflow: mid <= n/mid
        // This is mathematically equivalent to mid * mid <= n
        if (mid <= n / mid) {
            ans = mid;      // Mid is a potential answer
            low = mid + 1;  // Try to find a larger value
        } else {
            high = mid - 1; // Too large, search the left half
        }
    }

    return ans;
}

int main() {
    int n;
    // Prompt the user for input
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Square root of a negative number is not defined for integers.\n");
    } else {
        printf("%d\n", findIntegerSqrt(n));
    }

    return 0;
}