// Problem: Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

// Function to reverse a specific portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    k = k % n;
    if (k == 0) {
    } else {
        reverse(arr, 0, n - k - 1);
        
        reverse(arr, n - k, n - 1);
        
        reverse(arr, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}