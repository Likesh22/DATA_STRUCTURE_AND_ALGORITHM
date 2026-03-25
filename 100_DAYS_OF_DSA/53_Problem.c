// Problem Statement:Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

/*
Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
*/

// Explanation: Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

typedef struct {
    int val;
    int hd;    // Horizontal Distance
    int level; // Vertical Level
} NodeInfo;

// Create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
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

// Comparison for qsort: Sort by HD, then by Level
int compare(const void* a, const void* b) {
    NodeInfo* n1 = (NodeInfo*)a;
    NodeInfo* n2 = (NodeInfo*)b;
    if (n1->hd != n2->hd) return n1->hd - n2->hd;
    return n1->level - n2->level;
}

void printVerticalOrder(struct Node* root, int n) {
    if (!root) return;

    NodeInfo* list = malloc(sizeof(NodeInfo) * n);
    int count = 0;

    // BFS Queues
    struct Node* q[n];
    int hdQ[n], lvlQ[n];
    int f = 0, r = 0;

    q[r] = root; hdQ[r] = 0; lvlQ[r++] = 0;

    while (f < r) {
        struct Node* curr = q[f];
        int currHD = hdQ[f];
        int currLvl = lvlQ[f++];

        list[count].val = curr->data;
        list[count].hd = currHD;
        list[count++].level = currLvl;

        if (curr->left) {
            q[r] = curr->left; hdQ[r] = currHD - 1; lvlQ[r++] = currLvl + 1;
        }
        if (curr->right) {
            q[r] = curr->right; hdQ[r] = currHD + 1; lvlQ[r++] = currLvl + 1;
        }
    }

    qsort(list, count, sizeof(NodeInfo), compare);

    // Print output grouped by column
    printf("\nVertical Order Traversal:\n");
    for (int i = 0; i < count; i++) {
        if (i > 0 && list[i].hd != list[i - 1].hd) printf("\n");
        printf("%d ", list[i].val);
    }
    printf("\n");
    free(list);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printVerticalOrder(root, n);

    return 0;
}