// Problem Statement- Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
/*
Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void findFirstRepeated(char* s) {
    bool seen[26] = {false};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';

        // If we have seen this character before, it's our answer
        if (seen[index]) {
            printf("%c\n", s[i]);
            return;
        }

        // Otherwise, mark it as seen
        seen[index] = true;
    }

    // If no character is repeated
    printf("-1\n");
}

int main() {
    char s[100001];
    printf("Enter a string: ");
    if (scanf("%s", s) == 1) {
        findFirstRepeated(s);
    }
    return 0;
}