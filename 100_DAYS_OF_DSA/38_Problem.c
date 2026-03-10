/*
// Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node *next, *prev;
};

// Deque structure
typedef struct {
    struct Node *front, *rear;
    int size;
} Deque;

// Initialize Deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// 1. Push Front: O(1)
void push_front(Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

// 2. Push Back: O(1)
void push_back(Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

// 3. Pop Front: O(1)
int pop_front(Deque* dq) {
    if (dq->front == NULL) return -1;
    struct Node* temp = dq->front;
    int val = temp->data;

    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;

    free(temp);
    dq->size--;
    return val;
}

// 4. Pop Back: O(1)
int pop_back(Deque* dq) {
    if (dq->rear == NULL) return -1;
    struct Node* temp = dq->rear;
    int val = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;

    free(temp);
    dq->size--;
    return val;
}

// 5. Display: O(n)
void display(Deque* dq) {
    struct Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_front(dq, 1);
    
    printf("Deque after pushes: ");
    display(dq); // Expected: 1 5 10 20

    pop_front(dq);
    pop_back(dq);

    printf("Deque after pops: ");
    display(dq); // Expected: 5 10
    printf("Size: %d\n", dq->size);

    return 0;
}