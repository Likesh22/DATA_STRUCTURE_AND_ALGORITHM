// Problem Statement Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
/*
Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>

// Helper function to check if a limit 'maxPages' is feasible
int isPossible(int* pages, int n, int m, int maxPages) {
    int studentsUsed = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book is larger than the limit, impossible
        if (pages[i] > maxPages) return 0;

        if (currentPages + pages[i] > maxPages) {
            // Assign to new student
            studentsUsed++;
            currentPages = pages[i];
            
            // If we exceed available students, this limit is too small
            if (studentsUsed > m) return 0;
        } else {
            currentPages += pages[i];
        }
    }
    return 1;
}

int allocateBooks(int* pages, int n, int m) {
    if (m > n) return -1; // More students than books

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > low) low = pages[i];
        high += pages[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;     // Feasible, try a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;    // Not feasible, must increase maximum
        }
    }
    return result;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int pages[n];
    for (int i = 0; i < n; i++) {
        printf("Enter pages in book %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("%d\n", allocateBooks(pages, n, m));

    return 0;
}