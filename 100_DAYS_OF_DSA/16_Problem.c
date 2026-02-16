// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int i = 0;
    while (i < n) {
        int count = 1;
        int current_element = arr[i];
        
        while (i + 1 < n && arr[i + 1] == current_element) {
            count++;
            i++;
        }
        printf("%d:%d%s", current_element, count, (i == n - 1) ? "" : " ");
        i++;
    }
    printf("\n");

    return 0;
}