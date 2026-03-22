// Problem: BST Search
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
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive Search Function: O(H)
struct Node* search(struct Node* root, int val) {
    // Base Case: root is null (not found) or we found the value
    if (root == NULL || root->data == val) {
        return root;
    }

    // Val is greater than root's data, search right
    if (val > root->data) {
        return search(root->right, val);
    }

    // Val is smaller than root's data, search left
    return search(root->left, val);
}

int main() {
    /* Constructing the BST:
              50
            /    \
           30     70
          /  \   /  \
         20  40 60  80
    */
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    int key = 60;
    struct Node* result = search(root, key);

    if (result != NULL) {
        printf("Node %d found in the BST.\n", result->data);
    } else {
        printf("Node %d not found.\n", key);
    }

    return 0;
}