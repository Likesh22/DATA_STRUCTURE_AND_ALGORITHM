// Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

/*
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
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

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Standard BST Insertion
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Function to find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both nodes are smaller, LCA is in the left subtree
        if (p < root->data && q < root->data) {
            root = root->left;
        }
        // If both nodes are larger, LCA is in the right subtree
        else if (p > root->data && q > root->data) {
            root = root->right;
        }
        // If we found the split point, this is the LCA
        else {
            return root;
        }
    }
    return NULL;
}

int main() {
    int n, p, q;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter node value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);
    if (lca) printf("%d\n", lca->data);

    return 0;
}