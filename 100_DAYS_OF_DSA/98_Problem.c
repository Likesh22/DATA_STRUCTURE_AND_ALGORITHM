// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort by start time
int compareIntervals(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * returnSize: pointer to an int where we store the number of merged intervals
 * returnColumnSizes: pointer to an array of ints where we store the col size for each row
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    // 1. Sort intervals based on start time
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);

    // 2. Prepare result array (worst case: same size as input)
    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    // 3. Start with the first interval
    merged[count] = (int*)malloc(2 * sizeof(int));
    merged[count][0] = intervals[0][0];
    merged[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];
        int lastMergedEnd = merged[count - 1][1];

        if (currentStart <= lastMergedEnd) {
            // Overlap detected: Update the end of the last merged interval
            merged[count - 1][1] = MAX(lastMergedEnd, currentEnd);
        } else {
            // No overlap: Create a new interval in result
            merged[count] = (int*)malloc(2 * sizeof(int));
            merged[count][0] = currentStart;
            merged[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return merged;
}

int main() {
    // Example: [[1,3],[2,6],[8,10],[15,18]]
    int rows = 4;
    int** intervals = (int**)malloc(rows * sizeof(int*));
    int data[4][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
    
    for(int i = 0; i < rows; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        intervals[i][0] = data[i][0];
        intervals[i][1] = data[i][1];
    }

    int returnSize;
    int* returnColumnSizes;
    int** result = merge(intervals, rows, NULL, &returnSize, &returnColumnSizes);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
    }
    printf("\n");

    // Cleanup memory
    for(int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);
    
    return 0;
}