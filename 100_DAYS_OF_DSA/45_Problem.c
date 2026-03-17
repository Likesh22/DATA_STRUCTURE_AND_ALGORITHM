// Problem Statement: Find the height (maximum depth) of a given binary tree.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new tree node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Reconstruct tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
    return root;
}

// Recursive function to find height
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printf("%d\n", findHeight(root));

    return 0;
}