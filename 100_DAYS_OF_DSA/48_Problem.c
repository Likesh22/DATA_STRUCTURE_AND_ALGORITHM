// Problem: Count Leaf Nodes
/*
Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If node is null, it's not a leaf
    if (root == NULL) {
        return 0;
    }

    // If both children are null, it IS a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Otherwise, sum the leaves from both subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    /* Constructing the tree:
              1
            /   \
           2     3
          / \   /
         4   5 6    <-- 4, 5, and 6 are leaves
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    printf("Total Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}