// Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value
*/

#include <stdio.h>
#include <stdlib.h>

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

// Build tree from level-order input using a Queue
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
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
    return root;
}

// Recursive LCA function for a general Binary Tree
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q) {
        return root;
    }

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    // If both left and right are non-NULL, p and q are in different subtrees
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise return the one that is not NULL
    return (left != NULL) ? left : right;
}

int main() {
    int n, p, q;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) 
    {   printf("Enter node value (or -1 for NULL): ");
        scanf("%d", &arr[i]);
    }
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, p, q);

    if (lca) printf("%d\n", lca->data);

    return 0;
}