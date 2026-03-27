// Problem Statement: Print the nodes visible when the binary tree is viewed from the right side.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Reconstruct tree from level-order input
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

void printRightView(struct Node* root, int n) {
    if (!root) return;

    struct Node* queue[n];
    int f = 0, r = 0;
    queue[r++] = root;

    while (f < r) {
        int levelSize = r - f;
        
        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[f++];
            
            // If this is the last node of the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }
            
            if (curr->left) queue[r++] = curr->left;
            if (curr->right) queue[r++] = curr->right;
        }
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
    printRightView(root, n);

    return 0;
}