// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // 1. Find the maximum element to determine the range
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // 2. Build the frequency array (size max + 1)
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums (cumulative counts)
    // This tells us the actual position of this digit in output[]
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build the output array
    // We go backwards to make the sort STABLE
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 5. Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Clean up memory
    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}