// Problem Statement: Implement a Queue using a linked list supporting enqueue and dequeue operations.
/*
Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure to track both ends
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: O(1)
void enqueue(struct Queue* q, int x) {
    struct Node* newNode = createNode(x);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue: O(1)
int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;

    struct Node* temp = q->front;
    int val = temp->data;
    
    q->front = q->front->next;

    // If front becomes NULL, then rear must also become NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    int n;
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();
    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}