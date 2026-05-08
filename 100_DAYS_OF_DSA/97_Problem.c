// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int intervals[][2], int n) {
    if (n == 0) return 0;

    int startTimes[n];
    int endTimes[n];

    // 1. Separate starts and ends
    for (int i = 0; i < n; i++) {
        startTimes[i] = intervals[i][0];
        endTimes[i] = intervals[i][1];
    }

    // 2. Sort both independently
    qsort(startTimes, n, sizeof(int), compare);
    qsort(endTimes, n, sizeof(int), compare);

    int startPtr = 0, endPtr = 0;
    int roomsOccupied = 0;
    int maxRooms = 0;

    // 3. Two-pointer sweep
    while (startPtr < n) {
        if (startTimes[startPtr] < endTimes[endPtr]) {
            // A meeting started before another ended
            roomsOccupied++;
            startPtr++;
        } else {
            // A meeting ended, freeing a room
            roomsOccupied--;
            endPtr++;
        }
        
        // Track the peak occupancy
        if (roomsOccupied > maxRooms) {
            maxRooms = roomsOccupied;
        }
    }

    return maxRooms;
}

int main() {
    // Example: [[0, 30], [5, 10], [15, 20]]
    int intervals[3][2] = {{0, 30}, {5, 10}, {15, 20}};
    int n = 3;

    int result = minMeetingRooms(intervals, n);
    printf("Minimum rooms required: %d\n", result);

    return 0;
}