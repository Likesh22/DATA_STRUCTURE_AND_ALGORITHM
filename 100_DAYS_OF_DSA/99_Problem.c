// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

// Structure to hold car data
typedef struct {
    int pos;
    double time;
} Car;

// Comparator to sort cars by position in descending order
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    Car* cars = (Car*)malloc(positionSize * sizeof(Car));

    // 1. Calculate time to destination for each car
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // 2. Sort cars by starting position (closest to target first)
    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    // 3. Iterate through cars
    for (int i = 0; i < positionSize; i++) {
        // If this car takes more time than the current fleet leader,
        // it starts a new fleet.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
        // Otherwise, it catches up and merges into the existing fleet
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    int result = carFleet(target, position, n, speed, n);
    printf("Number of car fleets: %d\n", result);

    return 0;
}