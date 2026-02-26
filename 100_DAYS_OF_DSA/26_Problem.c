// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}