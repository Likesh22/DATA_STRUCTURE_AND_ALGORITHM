// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {

        printf("%d", temp->coeff);

        if (temp->expo > 0) {
            printf("x");
            if (temp->expo > 1) {
                printf("^%d", temp->expo);
            }
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    displayPolynomial(head);

    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}