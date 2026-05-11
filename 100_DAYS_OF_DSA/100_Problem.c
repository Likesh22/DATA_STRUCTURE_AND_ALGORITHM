// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include <stdio.h>
#include <stdlib.h>

// Structure to track the original index of each value
typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* counts, Element* temp) {
    int i = left;      // Left subarray pointer
    int j = mid + 1;   // Right subarray pointer
    int k = left;      // Temp array pointer
    int right_smaller_count = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            // Found an element on the right strictly smaller than the left element
            right_smaller_count++;
            temp[k++] = arr[j++];
        } else {
            // Left element is smaller or equal; update its smaller-to-right count
            counts[arr[i].index] += right_smaller_count;
            temp[k++] = arr[i++];
        }
    }

    // Process remaining elements in left subarray
    while (i <= mid) {
        counts[arr[i].index] += right_smaller_count;
        temp[k++] = arr[i++];
    }
    // Process remaining elements in right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to original array
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void solve(Element* arr, int left, int right, int* counts, Element* temp) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    solve(arr, left, mid, counts, temp);
    solve(arr, mid + 1, right, counts, temp);
    merge(arr, left, mid, right, counts, temp);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    int* counts = (int*)calloc(n, sizeof(int));
    Element* arr = (Element*)malloc(n * sizeof(Element));
    Element* temp = (Element*)malloc(n * sizeof(Element));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    solve(arr, 0, n - 1, counts, temp);

    printf("Input:  [5, 2, 6, 1]\n");
    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", counts[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");

    free(counts);
    free(arr);
    free(temp);
    return 0;
}