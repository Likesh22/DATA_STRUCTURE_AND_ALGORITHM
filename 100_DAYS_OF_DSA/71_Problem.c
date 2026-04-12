// Problem Statement-Implement a hash table using quadratic probing with formula:
// h(k, i) = (h(k) + i*i) % m
/*
Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMPTY -1

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) ht->table[i] = EMPTY;
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int index = ( (key % m) + (i * i) ) % m;
        if (ht->table[index] == EMPTY) {
            ht->table[index] = key;
            return;
        }
    }
}

void search(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int index = ( (key % m) + (i * i) ) % m;
        if (ht->table[index] == key) {
            printf("FOUND\n");
            return;
        }
        // In open addressing, hitting an EMPTY slot usually means key isn't there
        if (ht->table[index] == EMPTY) break;
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    printf("Enter hash table size and number of operations: ");
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);

    for (int i = 0; i < n; i++) {
        char op[10];
        int val;
        printf("Enter operation and value: ");
        scanf("%s %d", op, &val);

        if (strcmp(op, "INSERT") == 0) {
            insert(ht, val);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(ht, val);
        }
    }

    return 0;
}