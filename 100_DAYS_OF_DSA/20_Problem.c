// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    long long prefix_sums[n + 1];
    prefix_sums[0] = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        prefix_sums[i + 1] = prefix_sums[i] + arr[i];
    }

    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long current_freq = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            current_freq++;
        } else {
            count += (current_freq * (current_freq - 1)) / 2;
            current_freq = 1;
        }
    }
    count += (current_freq * (current_freq - 1)) / 2;

    printf("%lld\n", count);

    return 0;
}