// Problem Statement: Given a queue of integers, reverse the queue using a stack.
/*
Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue pointers
struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) return -1;
    struct Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

void reverseQueue(int n) {
    int stack[n];
    int top = -1;

    // Step 1: Dequeue from Queue and Push to Stack
    while (front != NULL) {
        stack[++top] = dequeue();
    }

    // Step 2: Pop from Stack and Enqueue back to Queue
    while (top != -1) {
        enqueue(stack[top--]);
    }
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &val) == 1) {
            enqueue(val);
        }
    }

    reverseQueue(n);
    display();

    return 0;
}