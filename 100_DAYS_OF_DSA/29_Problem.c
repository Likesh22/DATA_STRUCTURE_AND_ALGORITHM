// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

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
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    struct Node* last = head;
    int n = 1;
    while (last->next != NULL) {
        last = last->next;
        n++;
    }

    k = k % n;
    if (k == 0) return head;

    last->next = head;

    struct Node* newTail = head;
    for (int i = 1; i < n - k; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
    }
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    head = rotateRight(head, k);

    struct Node* temp = head;
    while (temp) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
    return 0;
}