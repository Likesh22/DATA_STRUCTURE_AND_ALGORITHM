// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
int main() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of elements in the circular linked list: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            tail = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d%s", temp->data, (temp->next == head) ? "" : " ");
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    if (head != NULL) {
        struct Node* curr = head;
        struct Node* nextNode;
        for (int i = 0; i < n; i++) {
            nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
    }
    return 0;
}