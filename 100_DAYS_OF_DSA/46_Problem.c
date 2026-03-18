// Problem: Level Order Traversal
/*
Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to perform Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    // Create a simple array-based queue
    struct Node* queue[100];
    int front = 0, rear = 0;

    // Enqueue Root
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue
        struct Node* curr = queue[front++];
        
        printf("%d ", curr->data);

        // Enqueue Left Child
        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }

        // Enqueue Right Child
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
}

int main() {
    /* Constructing the following tree:
              1
            /   \
           2     3
          / \
         4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}