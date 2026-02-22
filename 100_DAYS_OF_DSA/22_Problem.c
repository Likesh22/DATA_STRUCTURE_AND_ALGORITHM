// Problem: Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, value;
    printf("Enter the number of elements in the linked list: ");
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (scanf("%d", &value) != 1) break;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
    return 0;
}