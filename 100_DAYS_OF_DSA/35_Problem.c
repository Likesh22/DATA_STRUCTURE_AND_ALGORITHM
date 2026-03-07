// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure to track front and rear
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add element to the back
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = createNode(val);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int main() {
    int n, val;
    struct Queue* q = createQueue();

    // 1. Read size and enqueue elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(q, val);
    }

    // 2. Display from front to rear
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    // 3. Cleanup memory
    temp = q->front;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(q);

    return 0;
}