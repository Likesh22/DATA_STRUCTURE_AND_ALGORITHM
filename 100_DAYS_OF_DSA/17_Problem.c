// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}