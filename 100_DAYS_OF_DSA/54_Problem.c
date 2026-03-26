// Problem Statement:Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int f = 0, r = 0;
    queue[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[f++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[r++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[r++] = curr->right;
        }
    }
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;

    struct Node* queue[n];
    int f = 0, r = 0;
    queue[r++] = root;

    bool leftToRight = true;

    while (f < r) {
        int levelSize = r - f;
        int levelData[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[f++];
            
            // Calculate index based on current direction
            int index = leftToRight ? i : (levelSize - 1 - i);
            levelData[index] = curr->data;

            if (curr->left) queue[r++] = curr->left;
            if (curr->right) queue[r++] = curr->right;
        }

        // Print the current level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelData[i]);
        }
        
        // Flip direction for next level
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root, n);

    return 0;
}