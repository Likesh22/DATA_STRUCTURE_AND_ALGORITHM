// Problem: Count number of inversions using modified merge sort.
// Inversion if i < j and a[i] > a[j].

#include <stdio.h>
#include <stdlib.h>

long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long shifts = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            // L[i] > R[j], so all remaining elements in L 
            // (from current i to n1-1) are inversions.
            arr[k++] = R[j++];
            shifts += (n1 - i); 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
    return shifts;
}

long long int countInversions(int arr[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        count += countInversions(arr, l, m);
        count += countInversions(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long result = countInversions(arr, 0, n - 1);

    printf("Number of inversions: %lld\n", result);
    return 0;
}