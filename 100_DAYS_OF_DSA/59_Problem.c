// Problem Statement:Construct a binary tree from given inorder and postorder traversal arrays.
/*
Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to build the tree
struct Node* buildTree(int inorder[], int inStart, int inEnd, int postorder[], int* postIdx) {
    // Base case
    if (inStart > inEnd) return NULL;

    // 1. Pick current node from Postorder using postIdx and decrement postIdx
    int rootVal = postorder[*postIdx];
    struct Node* root = createNode(rootVal);
    (*postIdx)--;

    // 2. Find the index of this node in Inorder
    int inIdx;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            inIdx = i;
            break;
        }
    }

    // 3. Build RIGHT subtree first (because we are moving backwards in postorder)
    root->right = buildTree(inorder, inIdx + 1, inEnd, postorder, postIdx);
    
    // 4. Build LEFT subtree
    root->left = buildTree(inorder, inStart, inIdx - 1, postorder, postIdx);

    return root;
}

// Function to print Preorder Traversal
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int inorder[n], postorder[n];
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIdx = n - 1;
    struct Node* root = buildTree(inorder, 0, n - 1, postorder, &postIdx);

    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    return 0;
}