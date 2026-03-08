// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node *front, *rear;
} CircularQueue;

// Initialize Queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    q->rear->next = q->front; // Maintaining the circular link
}

// Dequeue operation
void dequeue(CircularQueue* q) {
    if (q->front == NULL) return;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Maintaining the circular link
        free(temp);
    }
}

// Function to print the queue
void display(CircularQueue* q) {
    if (q->front == NULL) return;
    
    struct Node* temp = q->front;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != q->front) printf(" ");
    } while (temp != q->front);
    printf("\n");
}

int main() {
    int n, m, val;
    CircularQueue* q = createQueue();

    // 1. Enqueue n elements
    printf("Enter the number of elements to enqueue: ");
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(q, val);
    }

    // 2. Dequeue m elements
    printf("Enter the number of elements to dequeue: ");
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    // 3. Display
    display(q);

    return 0;
}