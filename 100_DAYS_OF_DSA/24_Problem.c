// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create nodes
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, key, val;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    struct Node *curr = head, *prev = NULL;

    if (curr != NULL && curr->data == key) {
        head = curr->next;
        free(curr);
    } 
    else {
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
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