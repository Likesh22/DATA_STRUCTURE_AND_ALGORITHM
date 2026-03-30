// Problem Statement: Construct a binary tree from given preorder and inorder traversal arrays.
/*
Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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
struct Node* buildTree(int preorder[], int* preIdx, int inorder[], int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // 1. Pick current node from Preorder using preIdx and increment preIdx
    int rootVal = preorder[*preIdx];
    struct Node* root = createNode(rootVal);
    (*preIdx)++;

    // 2. If this node has no children then return
    if (inStart == inEnd) return root;

    // 3. Else find the index of this node in Inorder
    int inIdx;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            inIdx = i;
            break;
        }
    }

    // 4. Using index in Inorder, construct left and right subtrees
    root->left = buildTree(preorder, preIdx, inorder, inStart, inIdx - 1);
    root->right = buildTree(preorder, preIdx, inorder, inIdx + 1, inEnd);

    return root;
}

// Function to print Postorder Traversal
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int preorder[n], inorder[n];
    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIdx = 0;
    struct Node* root = buildTree(preorder, &preIdx, inorder, 0, n - 1);

    printf("Postorder Traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}