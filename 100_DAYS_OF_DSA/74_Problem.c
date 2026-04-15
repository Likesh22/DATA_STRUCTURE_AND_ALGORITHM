// Problem Statement -Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
/*
Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator for qsort to sort names lexicographically
int compareNames(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int n;
    printf("Enter number of votes: ");
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for pointers to names
    char** votes = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        votes[i] = (char*)malloc(101 * sizeof(char)); // Max name length 100
        printf("Enter vote %d: ", i + 1);
        scanf("%s", votes[i]);
    }

    // 1. Sort names alphabetically
    qsort(votes, n, sizeof(char*), compareNames);

    char* winner = votes[0];
    int maxVotes = 0;
    
    int currentVotes = 0;
    char* currentCandidate = votes[0];

    // 2. Linear pass to count frequencies
    for (int i = 0; i < n; i++) {
        if (strcmp(votes[i], currentCandidate) == 0) {
            currentVotes++;
        } else {
            // Check if previous candidate is the winner
            if (currentVotes > maxVotes) {
                maxVotes = currentVotes;
                winner = currentCandidate;
            }
            // Reset for the new candidate
            currentCandidate = votes[i];
            currentVotes = 1;
        }
    }

    // Final check for the last candidate in the loop
    if (currentVotes > maxVotes) {
        maxVotes = currentVotes;
        winner = currentCandidate;
    }

    // 3. Output result
    printf("%s %d\n", winner, maxVotes);

    // Cleanup
    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);

    return 0;
}